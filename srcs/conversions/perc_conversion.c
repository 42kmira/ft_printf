/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perc_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:32:07 by kmira             #+#    #+#             */
/*   Updated: 2019/08/07 22:27:52 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	perc_handler(t_format *format, ...)
{
	t_string	result;
	size_t		i;

	format->length = INT;
	result = apply_flags(format, 1);
	i = 0;
	while (result.output[i] != '\0' && result.output[i] != '1')
		i++;
	if (result.output[i] == '1')
		result.output[i] = '%';
	result.length = ft_strlen(result.output);
	result.free = TRUE;
	(void)format;
	return (result);
}
