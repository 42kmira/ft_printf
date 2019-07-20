/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:58:44 by kmira             #+#    #+#             */
/*   Updated: 2019/07/20 14:51:41 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	o_handler(t_format *format, unsigned long long value)
{
	t_string	result;

	result = apply_flags(format, value);
	if (format->specifier[0] == 'O')
		upper_case_string(result.output);
	result.length = ft_strlen(result.output);
	result.free = TRUE;
	return (result);
}
