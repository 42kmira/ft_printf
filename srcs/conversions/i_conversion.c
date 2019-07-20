/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:07:42 by kmira             #+#    #+#             */
/*   Updated: 2019/07/20 15:17:21 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	i_handler(t_format *format, long long value)
{
	t_string	result;
	int			arg_size;

	arg_size = get_arguement_size(format->specifier[0], format->length);
	result = apply_flags(format, value);
	result.length = ft_strlen(result.output);
	result.free = TRUE;
	return (result);
}
