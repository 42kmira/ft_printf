/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:57:18 by kmira             #+#    #+#             */
/*   Updated: 2019/07/11 22:48:30 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*s_handler(t_format *format, char *string)
{
	(void)string;
	(void)format;
	printf("%s", string);
	printf("S HANDLER\n");
	return ("S HANDLER");
}
