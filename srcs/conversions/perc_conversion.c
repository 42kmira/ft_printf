/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perc_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:32:07 by kmira             #+#    #+#             */
/*   Updated: 2019/07/13 13:00:19 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	perc_handler(t_format *format, ...)
{
	t_string	result;

	result.output = malloc(sizeof(*result.output) * (1));
	result.output[0] = '%';
	result.length = 1;
	result.free = TRUE;
	(void)format;
	return (result);
}
