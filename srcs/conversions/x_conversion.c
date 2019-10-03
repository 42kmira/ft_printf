/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 20:57:02 by kmira             #+#    #+#             */
/*   Updated: 2019/08/29 23:03:39 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
