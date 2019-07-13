/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 20:56:23 by kmira             #+#    #+#             */
/*   Updated: 2019/07/13 12:55:45 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	u_handler(t_format *format, unsigned long long value)
{
	t_string	result;

	result.free = FALSE;
	(void)format;
	(void)value;
	return (result);
}
