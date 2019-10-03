/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:58:13 by kmira             #+#    #+#             */
/*   Updated: 2019/08/28 21:32:48 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	p_handler(t_format *format, void *pointer)
{
	t_string	result;
	long long	pointer_value;
	int			sign;
	int			arg_size;

	pointer_value = (long long)pointer;
	arg_size = get_argument_size(format->specifier[0], format->length);
	pointer_value = correct_number(pointer_value, 0, arg_size, &sign);
	precision_padding(format, &result);
	make_number(pointer_value, NUM_SET, 16, &result);
	apply_flags_part_2(format, &result, pointer_value, sign);
	apply_flags_part_3(format, &result, pointer_value, sign);
	result.length = ft_strlen(result.output);
	return (result);
}
