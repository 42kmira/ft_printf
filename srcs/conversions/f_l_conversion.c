/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_l_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 02:18:55 by kmira             #+#    #+#             */
/*   Updated: 2019/08/16 16:58:37 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	f_handler_long(t_format *format, long double value)
{
	t_string	result;
	char		buffer_fixed[6000 + 62];
	char		*buffer;
	int			sign;

	if (format->precision < 6000 + 61)
	{
		ft_bzero(buffer_fixed, sizeof(buffer_fixed));
		buffer = buffer_fixed;
	}
	else
	{
		buffer = malloc(sizeof(*buffer) * (format->precision + 100));
		ft_bzero(buffer, format->precision + 100);
	}
	result = precision(format, value, &buffer, &sign);
	result.length = ft_strlen(result.output);
	if (format->precision != -1 && format->precision != 0)
		format->precision = format->precision;
	if (format->precision == -1)
		format->precision = 6;
	handle_float_flags(format, &result, sign);
	result.length = ft_strlen(result.output);
	return (result);
}
