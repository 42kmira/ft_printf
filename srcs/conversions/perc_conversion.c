/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perc_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:32:07 by kmira             #+#    #+#             */
/*   Updated: 2019/07/11 22:39:24 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*perc_handler(t_format *format, ...)
{
	(void)format;
	printf("PERC HANDLER\n");
	return ("% Handler");
}
