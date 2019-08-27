/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 20:57:02 by kmira             #+#    #+#             */
/*   Updated: 2019/08/22 20:16:27 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Pass a buffer that can hold any number which you wish to convert.
** Return the adress. If you need to append the 0x to the front
** you can just go two back in address space and add them there.
** you can make a certain buffer for padding and if the necessary.
** If padding is more then you can enter a slower loop to padd,
** but under other conditions then it padds the number faster.
*/

/*
** Buffer for the entire string?
** Maybe a structure for it that holds the place and maybe
** does the buffer flush if necessary.
*/

t_string	x_handler(t_format *format, unsigned long long value)
{
	t_string	result;
	int			sign;
	int			arg_size;

	arg_size = get_argument_size(format->specifier[0], format->length);
	value = correct_number(value, 0, arg_size, &sign);
	precision_padding(format, &result);
	make_number(value, NUM_SET, 16, &result);
	apply_flags_part_2(format, &result, value, sign);
	apply_flags_part_3(format, &result, value, sign);
	if (format->specifier[0] == 'X')
		ft_strupr(result.output);
	result.length = ft_strlen(result.output);
	return (result);
}
