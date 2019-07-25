/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 20:55:14 by kmira             #+#    #+#             */
/*   Updated: 2019/07/25 01:10:13 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <sys/_endian.h>

#define DOUB_EXP_BIAS 1023
#define LONG_EXP_BIAS 16383

union				u_ieee2_d
{
	double			type;
	struct
	{
		unsigned long	mantissa	: 52;
		unsigned int	exp			: 11;
		unsigned int	sign		: 1;
	}	bits;
}					u_double_bit;

union					u_ieee2_ld
{
	long double	type;
	struct
	{
		unsigned long	mantissa	:64;
		unsigned int	exp			:15;
		unsigned int	sign		:1;
	}					bits;

}						u_long_double_bit;

union	u_ieee2bits
{
		union u_ieee2_d		double_;
		union u_ieee2_ld	long_double_;
}		u_iee2bits;


		// while (number[j] != '\0' && number[j] != '.')
		// {
		// 	sum = carry * 10 + (number[j] - '0');
		// 	number[j] = base[sum / 2];
		// 	carry = sum % 2;
		// 	j++;
		// }
		// if (carry == 1 || number[j] == '.')
		// {
		// 	if (number[j] != '.')
		// 	{
		// 		number[j] = '.';
		// 		number[j + 1] = '0';
		// 	}
		// 	else
		// 		number[j] = '.';
		// 	j++;
		// 	while (number[j] != '\0' || carry == 1)
		// 	{
		// 		if (number[j] == '\0')
		// 			number[j] = '0';
		// 		sum = carry * 10 + (number[j] - '0');
		// 		number[j] = base[sum / 2];
		// 		carry = sum % 2;
		// 		j++;
		// 	}
		// }

void		divide_string(char *base, t_string *string, int exp)
{
	int		j;
	char	number[52 + 1023];
	int		sum;
	int		carry;
	int		dot;

	ft_bzero(number, sizeof(number));
	ft_strcpy(number, string->output);
	while (exp != 0)
	{
		j = 0;
		carry = 0;
		dot = 0;
		while (number[j] != '\0' || carry == 1)
		{
			sum = carry * 10 + (number[j] - '0');
			number[j++] = base[sum / 2];
			carry = sum % 2;
			if ((number[j] == '\0' && carry == 1 && dot == 0) || number[j] == '.')
			{
				number[j++] = '.';
				dot = 1;
			}
			if (carry == 1 && number[j] == '\0')
				number[j] = '0';
		}
		exp++;
	}
	string->output = ft_strdup(number);
}

void		precision(t_format *format, long double value)
{
	union u_ieee2bits	bits;
	int					sign;
	int					exp;

	long num;

	if (format->length != XL)
	{
		bits.double_.type = value;
		sign = bits.double_.bits.sign;
		exp = bits.double_.bits.exp - DOUB_EXP_BIAS - 52;
		num = bits.double_.bits.mantissa | (1L << 52);
	}
	else
	{
		bits.long_double_.type = value;
		sign = bits.long_double_.bits.sign;
		exp = bits.long_double_.bits.exp - LONG_EXP_BIAS - 63;
		num = bits.long_double_.bits.mantissa;
	}

	if (sign)
		printf("NEG Number\n");
	else
		printf("POS Number\n");

	t_string	string;
	string.output = malloc(sizeof(*(string.output)) * (54));
	ft_bzero(string.output, 52);
	make_number(num, "0123456789", 10, &string);
	ft_strrev(string.output);

	divide_string("0123456789", &string, exp);

	printf("OUT STRING: %s\n", string.output);
	printf("EXP: %d\n", exp);


	(void)format;
}

t_string	f_handler_double(t_format *format, double value)
{
	t_string	result;

	result.output = "Float: ";
	result.length = 7;
	result.free = FALSE;

	precision(format, value);


	(void)format;
	(void)value;
	return (result);
}

t_string	f_handler_long(t_format *format, long double value)
{
	t_string	result;

	result.output = "Doubl: ";
	result.length = 7;
	result.free = FALSE;

	precision(format, value);

	(void)format;
	(void)value;
	return (result);
}
