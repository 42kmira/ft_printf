/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:57:38 by kmira             #+#    #+#             */
/*   Updated: 2019/07/13 19:07:45 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		lltoa(long long value, char buffer, int radix, int neg)
{

}

t_string	d_handler(t_format *format, long long value)
{
	t_string	result;


	result.output = NULL;
	result.free = TRUE;
	(void)format;
	(void)value;
	return (result);
}
