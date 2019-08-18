/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:07:42 by kmira             #+#    #+#             */
/*   Updated: 2019/08/16 17:09:03 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	i_handler(t_format *format, long long value)
{
	t_string	result;

	result = apply_flags(format, value);
	result.length = ft_strlen(result.output);
	result.free = TRUE;
	return (result);
}
