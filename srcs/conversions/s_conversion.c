/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:57:18 by kmira             #+#    #+#             */
/*   Updated: 2019/07/13 12:59:07 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	s_handler(t_format *format, char *string)
{
	t_string	result;

	result.output = string;
	result.length = ft_strlen(string);
	result.free = FALSE;
	(void)format;
	return (result);
}
