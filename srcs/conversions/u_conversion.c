/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 20:56:23 by kmira             #+#    #+#             */
/*   Updated: 2019/07/25 04:55:14 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	u_handler(t_format *format, unsigned long long value)
{
	t_string	result;
	int			arg_size;

	arg_size = get_arguement_size(format->specifier[0], format->length);
	result.output = ft_ntoa(value, 0, arg_size, NUM_SET, 10);
	result.length = ft_strlen(result.output);
	result.free = TRUE;
	return (result);
}
