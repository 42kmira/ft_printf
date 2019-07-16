/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:57:38 by kmira             #+#    #+#             */
/*   Updated: 2019/07/16 14:13:59 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

void		print_binary(long long input)
{
	int			i;
	long long	bit_mask;

	i = 0;
	bit_mask = 1;
	printf("BINARY: ");
	while (i < 64)
	{
		if (i != 0 && i % 4 == 0)
			printf(" ");
		if (bit_mask & input)
			printf("1");
		else
			printf("0");
		i++;
		bit_mask = bit_mask << 1;
	}
	printf("\n");
}

// long long	signed_mask(int signed_bit)
// {
// 	long long	mask;
// 	int			i;

// 	i = 0;
// 	mask = 0;
// 	while (i < signed_bit)
// 	{
// 		mask = mask << 8;
// 		mask = mask | 0b11111111;
// 		i++;
// 	}
// 	return (mask);
// }

// char	*lltoa(unsigned long long value, int signed_bit, int length)
// {
// 	int			neg_sign;
// 	int			i;
// 	char		*result;
// 	long long	mask;

// 	result = malloc(sizeof(*result) * 21);
// 	ft_bzero(result, 21);
// 	mask = signed_mask(length);
// 	neg_sign = (value & (1ULL << (signed_bit * 8 - 1))) ? 1 : 0;
// 	if (neg_sign)
// 	{
// 		value = value * -1 - 1;
// 		value = value & mask;
// 		value = value + 1;
// 	}
// 	i = 0;
// 	while (value > 0)
// 	{
// 		result[i] = value % 10 + '0';
// 		value = value / 10;
// 		i++;
// 	}
// 	if (neg_sign)
// 		result[i] = '-';
// 	return (ft_strrev(result));
// }

/*
** FLAGS:
** 		VALID FLAGS: -+ 0
** 			VALID FLAGS: 4/5
** 		INVALID FLAGS: #
** 			INVALID FLAGS: 1/5
**
** WIDTH:
** 		Is always applicable.
**
** PRECISION:
** 		For integer specifiers (d, i, o, u, x, X):
**		precision specifies the minimum number of
**		digits to be written. If the value to be written
**		is shorter than this number, the result is padded
**		with leading zeros. The value is not truncated even
**		if the result is longer. A precision of 0 means that
**		no character is written for the value 0.
*/

t_string	d_handler(t_format *format, long long value)
{
	t_string	result;
	int			arg_size;

	arg_size = get_arguement_size(format->specifier[0], format->length);
	result.output = ft_ntoa(value, arg_size, arg_size, NUM_SET, 10);
	result.length = ft_strlen(result.output);
	result.free = TRUE;
	return (result);
}
