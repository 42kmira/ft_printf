/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_l_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 02:18:55 by kmira             #+#    #+#             */
/*   Updated: 2019/08/21 03:36:02 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	f_handler_long(t_format *format, long double value)
{
	t_string	result;
	char		*buffer;
	int			sign;

	buffer = malloc(sizeof(*buffer) * (format->precision + 6000));
	ft_bzero(buffer, format->precision + 6000);
	result = precision(format, value, &buffer, &sign);
	result.length = ft_strlen(result.output);
	if (format->precision == -1)
		format->precision = 6;
	handle_float_flags(format, &result, sign);
	result.length = ft_strlen(result.output);
	return (result);
}
