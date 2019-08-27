/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:07:42 by kmira             #+#    #+#             */
/*   Updated: 2019/08/22 20:16:27 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	i_handler(t_format *format, long long value)
{
	t_string	result;
	int			sign;
	int			arg_size;

	arg_size = get_argument_size(format->specifier[0], format->length);
	value = correct_number(value, arg_size, arg_size, &sign);
	precision_padding(format, &result);
	make_number(value, NUM_SET, 10, &result);
	apply_flags_part_2(format, &result, value, sign);
	apply_flags_part_3(format, &result, value, sign);
	result.length = ft_strlen(result.output);
	return (result);
}
