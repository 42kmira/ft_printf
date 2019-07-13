/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:58:13 by kmira             #+#    #+#             */
/*   Updated: 2019/07/13 12:53:22 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

t_string	p_handler(t_format *format, void *pointer)
{
	t_string	result;

	result.output = NULL;
	result.free = FALSE;
	(void)pointer;
	(void)format;
	return (result);
}
