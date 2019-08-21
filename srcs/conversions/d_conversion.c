/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:57:38 by kmira             #+#    #+#             */
/*   Updated: 2019/08/21 03:25:01 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

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
	int			sign;
	int			arg_size;

	arg_size = get_arguement_size(format->specifier[0], format->length);
	value = correct_number(value, arg_size, arg_size, &sign);
	precision_padding(format, &result);
	make_number(value, NUM_SET, 10, &result);
	apply_flags_part_2(format, &result, value, sign);
	apply_flags_part_3(format, &result, value, sign);
	result.length = ft_strlen(result.output);
	return (result);
}
