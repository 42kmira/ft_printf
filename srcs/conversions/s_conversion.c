/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:57:18 by kmira             #+#    #+#             */
/*   Updated: 2019/07/20 14:33:39 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	s_handler(t_format *format, char *string)
{
	t_string	result;

	if (string == NULL)
		result.output = "(null)";
	else
		result.output = string;
	result.length = ft_strlen(result.output);
	result.free = FALSE;
	(void)format;
	return (result);
}
