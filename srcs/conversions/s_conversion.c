/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:57:18 by kmira             #+#    #+#             */
/*   Updated: 2019/08/21 02:49:45 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	s_handler(t_format *format, char *string)
{
	t_string	result;

	if (string == NULL)
		string = "(null)";
	result.output = string;
	result.length = ft_strlen(result.output);
	if (result.length > format->precision && format->precision != -1)
		result.length = format->precision;
	result.free = FALSE;
	if (format->width > result.length)
	{
		result.output = malloc(sizeof(*(result.output)) * (format->width));
		result.free = TRUE;
		ft_memset(result.output, ' ', format->width);
		if (format->flags & MINUS_FLAG)
			ft_strncpy(result.output, string, result.length);
		else
			ft_strncpy(&result.output[format->width - result.length],
			string, result.length);
		result.length = format->width;
	}
	return (result);
}
