/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_l_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 02:18:55 by kmira             #+#    #+#             */
/*   Updated: 2019/08/28 21:32:26 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		buffer_fix(char **buffer, int exp)
{
	char	*buff;

	if (-exp > 1000)
	{
		buff = malloc(sizeof(*buff) * (-exp + 1));
		ft_bzero(buff, -exp + 1);
		ft_strcpy(buff, *buffer);
		free(*buffer);
		*buffer = buff;
	}
}

/*
** The buffer for a long double has to be at least as big as the largest
** number. This in theory is the exponent plus the length of mantissa.
**
** For a long double I believe the total chars is 16,384, the bias of the
** exponent. Here is use half that value that is seems to work however.
*/

t_string	f_handler_long(t_format *format, long double value)
{
	t_string	result;
	char		*buffer;
	int			sign;

	buffer = malloc(sizeof(*buffer) * (format->precision + 8042 + 54));
	ft_bzero(buffer, format->precision + 8042 + 53);
	result = make_float_number(format, value, &buffer, &sign);
	result.length = ft_strlen(result.output);
	if (format->precision == -1)
		format->precision = 6;
	normalize_float(&result);
	handle_float_flags(format, &result, sign);
	result.length = ft_strlen(result.output);
	return (result);
}
