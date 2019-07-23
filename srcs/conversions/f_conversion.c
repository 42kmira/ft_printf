/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 20:55:14 by kmira             #+#    #+#             */
/*   Updated: 2019/07/23 14:46:13 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <sys/_endian.h>

union				u_ieee2_d
{
	double			type;
	struct
	{
		unsigned long	mantissa	: 48;
		unsigned int	exp			: 15;
		unsigned int	sign		: 1;
	}	bits;
}					u_double_bit;

union					u_ieee2_ld
{
	long double	type;
	struct
	{
		unsigned long	manl	:64;
		unsigned int	exp		:15;
		unsigned int	sign	:1;
	}					bits;

}						u_long_double_bit;

union	u_ieee2bits
{
		union u_ieee2_d		double_;
		union u_ieee2_ld	long_double_;
}		u_iee2bits;

void		precision(t_format *format, long double value)
{
	union u_ieee2bits	bits;
	int					sign;


	if (format->length != XL)
	{
		bits.double_.type = value;
		sign = bits.double_.bits.sign;
	}
	else
	{
		bits.long_double_.type = value;
		sign = bits.long_double_.bits.sign;
	}

	if (sign)
		printf("NEG Number\n");
	else
		printf("POS Number\n");

	(void)format;
}

t_string	f_handler_double(t_format *format, double value)
{
	t_string	result;

	result.output = "";
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

	result.output = "FLOAT: ";
	result.length = 7;
	result.free = FALSE;

	precision(format, value);

	(void)format;
	(void)value;
	return (result);
}
