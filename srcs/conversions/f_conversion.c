/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 20:55:14 by kmira             #+#    #+#             */
/*   Updated: 2019/07/25 04:20:29 by kmira            ###   ########.fr       */
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

void		divide_string(char *base, char *buffer, int exp)
{
	int		j;
	int		sum;
	int		carry;
	int		dot;

	while (exp != 0)
	{
		j = 0;
		carry = 0;
		dot = 0;
		while (buffer[j] != '\0' || carry == 1)
		{
			sum = carry * 10 + (buffer[j] - '0');
			buffer[j++] = base[sum / 2];
			carry = sum % 2;
			if ((buffer[j] == '\0' && carry == 1 && dot == 0))
				buffer[j] = '.';
			if (buffer[j] == '.' && j++)
				dot = 1;
			if (carry == 1 && buffer[j] == '\0')
				buffer[j] = '0';
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

t_string	precision(t_format *format, long double value, char *buffer, int *sign)
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
		ft_strcpy(buffer, string.output);
		divide_string("0123456789", buffer, exp);
	}
	else if (exp > 0)
	{
		ft_strcpy(buffer, string.output);
		multiply_string("0123456789", buffer, exp);
		ft_strrev(buffer);
	}
	string.output = ft_strdup(buffer);
	return (string);
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
	if (format->flags & PLUS_FLAG || sign)
		sign_offset = 1;
	if (sign)
		string->output[0] = '-';
	else if (sign_offset)
		string->output[0] = '+';

	ft_memmove(&string->output[sign_offset], &(string->output[j]), string->length);
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
	string->output[j + i] = '\0';
}

t_string	f_handler_double(t_format *format, double value)
{
	t_string	result;
	char		buffer[1023 + 50];
	int			sign;

	ft_bzero(buffer, sizeof(buffer));
	result = precision(format, value, buffer, &sign);
	result.length = ft_strlen(result.output);

	if (format->precision != -1)
		format->precision = format->precision + 1;
	if (format->precision == -1)
		format->precision = 6;
	handle_float_flags(format, &result, sign);

	result.length = ft_strlen(result.output);

	return (result);
}

t_string	f_handler_long(t_format *format, long double value)
{
	t_string	result;
	char		buffer[1023 + 50];
	int			sign;

	ft_bzero(buffer, sizeof(buffer));
	result = precision(format, value, buffer, &sign);
	result.length = ft_strlen(result.output);

	if (format->precision != -1 && format->precision != 0)
		format->precision = format->precision + 1;
	if (format->precision == -1)
		format->precision = 6;
	handle_float_flags(format, &result, sign);

	result.length = ft_strlen(result.output);

	return (result);
}
