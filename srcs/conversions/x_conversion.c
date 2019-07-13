/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 20:57:02 by kmira             #+#    #+#             */
/*   Updated: 2019/07/13 12:57:54 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	x_handler(t_format *format, unsigned long long value)
{
	t_string	result;

	result.free = TRUE;
	(void)format;
	(void)value;
	return (result);
}
