/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 02:15:47 by kmira             #+#    #+#             */
/*   Updated: 2019/08/21 02:00:57 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define DOUB_EXP_BIAS 1023
#define LONG_EXP_BIAS 16383

void		buffer_fix(char **buffer, int exp)
{
	char	*buff;

	if (-exp > 1000)
	{
		buff = malloc(sizeof(*buff) * (-exp + 1));
		ft_bzero(buff, -exp + 1);
		ft_strcpy(buff, *buffer);
		free(*buffer);
		*buffer = buff;
	}
}

void		divide_string(char *base, char **buffer, int exp)
{
	int		j;
	int		sum;
	int		carry;
	int		dot;

	buffer_fix(buffer, exp);
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

void		make_longer(t_string *string, int exp, char **buff)
{
	if (exp < 0)
	{
		ft_strrev(string->output);
		ft_strcpy(*buff, string->output);
		divide_string("0123456789", buff, exp);
	}
	else if (exp > 0)
	{
		ft_strcpy(*buff, string->output);
		multiply_string("0123456789", *buff, exp);
		ft_strrev(*buff);
	}
	free(string->output);
	string->output = *buff;
}

t_string	precision(t_format *format, long double val, char **buff, int *sign)
{
	union u_ieee2bits	bits;
	int					exp;
	long				num;
	t_string			string;

	if (format->length != XL)
	{
		bits.double_.type = val;
		*sign = bits.double_.bits.sign;
		exp = bits.double_.bits.exp - DOUB_EXP_BIAS - 52;
		num = bits.double_.bits.mantissa | (1L << 52);
	}
	else
	{
		bits.long_double_.type = val;
		*sign = bits.long_double_.bits.sign;
		exp = bits.long_double_.bits.exp - LONG_EXP_BIAS - 63;
		num = bits.long_double_.bits.mantissa;
	}
	string.output = malloc(sizeof(*(string.output)) * (54));
	ft_bzero(string.output, 52);
	make_number(num, "0123456789", 10, &string);
	make_longer(&string, exp, buff);
	return (string);
}
