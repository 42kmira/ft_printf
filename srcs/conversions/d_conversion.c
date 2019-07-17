/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:57:38 by kmira             #+#    #+#             */
/*   Updated: 2019/07/16 21:55:50 by kmira            ###   ########.fr       */
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
