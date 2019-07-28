/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 20:55:14 by kmira             #+#    #+#             */
/*   Updated: 2019/07/28 06:03:10 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <sys/_endian.h>

#define DOUB_EXP_BIAS 1023
#define LONG_EXP_BIAS 16383

union					u_ieee2_d
{
	double				type;
	struct
	{
		unsigned long	mantissa	: 52;
		unsigned int	exp			: 11;
		unsigned int	sign		: 1;
	}	bits;
}					u_double_bit;

union					u_ieee2_ld
{
	long double			type;
	struct
	{
		unsigned long	mantissa	:64;
		unsigned int	exp			:15;
		unsigned int	sign		:1;
	}					bits;

}						u_long_double_bit;

union						u_ieee2bits
{
		union u_ieee2_d		double_;
		union u_ieee2_ld	long_double_;
}							u_iee2bits;

void		divide_string(char *base, char **buffer, int exp)
{
	int		j;
	int		sum;
	int		carry;
	int		dot;
	char	*buff;

	if (-exp > 1000)
	{
		buff = malloc(sizeof(*buff) * (-exp + 1));
		ft_bzero(buff, -exp + 1);
		ft_strcpy(buff, *buffer);
		*buffer = buff;
	}
	while (exp != 0)
	{
		j = 0;
		carry = 0;
		dot = 0;
		while ((*buffer)[j] != '\0' || carry == 1)
		{
			sum = carry * 10 + ((*buffer)[j] - '0');
			(*buffer)[j++] = base[sum / 2];
			carry = sum % 2;
			if (((*buffer)[j] == '\0' && carry == 1 && dot == 0))
				(*buffer)[j] = '.';
			if ((*buffer)[j] == '.' && j++)
				dot = 1;
			if (carry == 1 && (*buffer)[j] == '\0')
				(*buffer)[j] = '0';
		}
		exp++;
	}
}

void		multiply_string(char *base, char *buffer, int exp)
{
	int		j;
	int		sum;
	int		carry;

	while (exp != 0)
	{
		j = 0;
		carry = 0;
		while (buffer[j] != '\0')
		{
			sum = (buffer[j] - '0') * 2 + carry;
			buffer[j] = base[sum % 10];
			carry = sum / 10;
			j++;
		}
		if (carry == 1)
			buffer[j] = '1';
		exp--;
	}
}

t_string	precision(t_format *format, long double value, char **buffer, int *sign)
{
	union u_ieee2bits	bits;
	int					exp;
	long num;


	if (format->length != XL)
	{
		bits.double_.type = value;
		*sign = bits.double_.bits.sign;
		exp = bits.double_.bits.exp - DOUB_EXP_BIAS - 52;
		num = bits.double_.bits.mantissa | (1L << 52);
	}
	else
	{
		bits.long_double_.type = value;
		*sign = bits.long_double_.bits.sign;
		exp = bits.long_double_.bits.exp - LONG_EXP_BIAS - 63;
		num = bits.long_double_.bits.mantissa;
	}

	t_string	string;
	string.output = malloc(sizeof(*(string.output)) * (54));
	ft_bzero(string.output, 52);
	make_number(num, "0123456789", 10, &string);

	if (exp < 0)
	{
		ft_strrev(string.output);
		ft_strcpy(*buffer, string.output);
		divide_string("0123456789", buffer, exp);
	}
	else if (exp > 0)
	{
		ft_strcpy(*buffer, string.output);
		multiply_string("0123456789", *buffer, exp);
		ft_strrev(*buffer);
	}
	string.output = *buffer;
	return (string);
}

void		round_float(t_format *format, t_string *string)
{
	int	i;
	int	j;
	int	round_begin;
	int carry;

	i = 0;
	while (string->output[i] != '.')
		i++;

	j = 0;
	while (string->output[j] != '\0')
		j++;
	round_begin = i + format->precision + 1;
	carry = 0;
	if (string->output[round_begin] >= '5')
		carry = 1;

	round_begin--;
	while (round_begin != 0 && carry == 1)
	{
		carry = 0;
		if (string->output[round_begin] == '.')
			round_begin--;
		if (string->output[round_begin] == '9')
		{
			string->output[round_begin] = '0';
			carry = 1;
		}
		else
		{
			string->output[round_begin] = string->output[round_begin] + 1;
		}
		round_begin--;
	}
}

void		handle_float_flags(t_format *format, t_string *string, int sign)
{
	int		j;
	int		i;
	int		sign_offset;

	j = 0;
	while (j < string->length && string->output[j] == '0')
		j++;
	if (string->output[j] == '.')
		j--;
	sign_offset = 0;
	ft_memmove(string->output, &(string->output[j]), string->length);
	j = sign_offset;
	while (string->output[j] != '\0' && string->output[j] != '.')
		j++;
	if (format->precision != 0 && string->output[j] != '.')
		string->output[j] = '.';
	if (string->output[j] == '.')
		j++;
	i = 0;
	while (i < format->precision)
	{
		if (string->output[i + j] == '\0')
		{
			string->output[i + j] = '0';
			string->output[i + j + 1] = '\0';
		}
		i++;
	}
	round_float(format, string);
	string->output[j + i] = '\0';


	if (string->output[j + i - 1] == '.' && !(format->flags & HASH_FLAG))
		string->output[j + i - 1] = '\0';

	if (string->output[0] == '.')
		string->output = append("0", string->output);

	if (format->flags & MINUS_FLAG)
		format->flags = format->flags & ~ZERO_FLAG;
	if (format->flags & PLUS_FLAG)
		format->flags = format->flags & ~SPACE_FLAG;
	string->length = ft_strlen(string->output);
	if (format->flags & ZERO_FLAG && (format->flags & PLUS_FLAG || sign))
		format->width = format->width - 1;

	// printf("STRING %s\n", string->output);

	if (!(format->flags & ZERO_FLAG))
	{
		if (sign == 1)
			string->output = append("-", string->output);
		else if (format->flags & PLUS_FLAG)
			string->output = append("+", string->output);
		else if (format->flags & SPACE_FLAG)
			string->output = append(" ", string->output);
		string->length = ft_strlen(string->output);
	}

	// printf("STRING %s\n", string->output);

	char	*padding;
	int		minus;
	padding = malloc(sizeof(*padding) * (format->width + 1));
	ft_bzero(padding, format->width + 1);
	if (format->flags & ZERO_FLAG)
		ft_memset(padding, '0', format->width);
	else
		ft_memset(padding, ' ', format->width);
	minus = 0;
	if (format->flags & MINUS_FLAG)
		minus = 1;
	string->output = combine_padding(padding, string->output, minus);
	if (format->flags & ZERO_FLAG)
	{
		if (sign == 1)
			string->output = append("-", string->output);
		else if (format->flags & PLUS_FLAG)
			string->output = append("+", string->output);
		else if (format->flags & SPACE_FLAG && string->output[0] == '0' && string->output[1] == '0')
			string->output[0] = ' ';
		else if (format->flags & SPACE_FLAG)
			string->output = append(" ", string->output);
	}
}

t_string	f_handler_double(t_format *format, double value)
{
	t_string	result;
	char		*buffer;
	char		buffer_fixed[1023 + 50 + 1];
	int			sign;

	if (format->precision < 1023 + 50)
	{
		ft_bzero(buffer_fixed, sizeof(buffer_fixed));
		buffer = buffer_fixed;
	}
	else
	{
		buffer = malloc(sizeof(*buffer) * (format->precision + 1023));
		ft_bzero(buffer, format->precision + 1023);
	}

	result = precision(format, value, &buffer, &sign);

	result.length = ft_strlen(result.output);

	if (format->precision != -1)
		format->precision = format->precision;
	if (format->precision == -1)
		format->precision = 6;
	handle_float_flags(format, &result, sign);

	result.length = ft_strlen(result.output);

	return (result);
}

t_string	f_handler_long(t_format *format, long double value)
{
	t_string	result;
	char		buffer_fixed[6000 + 62];
	char		*buffer;
	int			sign;

	if (format->precision < 6000 + 61)
	{
		ft_bzero(buffer_fixed, sizeof(buffer_fixed));
		buffer = buffer_fixed;
	}
	else
	{
		buffer = malloc(sizeof(*buffer) * (format->precision + 100));
		ft_bzero(buffer, format->precision + 100);
	}

	result = precision(format, value, &buffer, &sign);
	result.length = ft_strlen(result.output);


	if (format->precision != -1 && format->precision != 0)
		format->precision = format->precision;
	if (format->precision == -1)
		format->precision = 6;
	handle_float_flags(format, &result, sign);

	result.length = ft_strlen(result.output);


	return (result);
}
