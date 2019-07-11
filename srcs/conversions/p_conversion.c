/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:58:13 by kmira             #+#    #+#             */
/*   Updated: 2019/07/11 12:44:54 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char	*p_handlers(t_format *format, void *pointer)
{
	(void)pointer;
	(void)format;
	return ("P HANDLER");
}
