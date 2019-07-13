/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:55:44 by kmira             #+#    #+#             */
/*   Updated: 2019/07/13 13:14:49 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	c_handler(t_format *format, int c)
{
	t_string	result;

	result.output = result.single;
	result.output[0] = c;
	result.length = 1;
	result.free = FALSE;
	(void)format;
	(void)c;
	return (result);
}
