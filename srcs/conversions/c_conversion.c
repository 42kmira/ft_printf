/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:55:44 by kmira             #+#    #+#             */
/*   Updated: 2019/07/12 20:30:23 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*c_handler(t_format *format, int c)
{
	(void)c;
	(void)format;
	printf("Here\n");
	return ("C HANDLER\n");
}
