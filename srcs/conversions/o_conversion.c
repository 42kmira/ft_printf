/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:58:44 by kmira             #+#    #+#             */
/*   Updated: 2019/08/21 03:25:41 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	o_handler(t_format *format, unsigned long long value)
{
	t_string	result;
	int			sign;
	int			arg_size;

	arg_size = get_arguement_size(format->specifier[0], format->length);
	value = correct_number(value, 0, arg_size, &sign);
	precision_padding(format, &result);
	make_number(value, NUM_SET, 8, &result);
	apply_flags_part_2(format, &result, value, sign);
	apply_flags_part_3(format, &result, value, sign);
	result.length = ft_strlen(result.output);
	return (result);
}
