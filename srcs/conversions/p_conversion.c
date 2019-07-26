/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:58:13 by kmira             #+#    #+#             */
/*   Updated: 2019/07/26 04:07:28 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

t_string	p_handler(t_format *format, void *pointer)
{
	t_string	result;
	int			arg_size;

	arg_size = get_arguement_size(format->specifier[0], format->length);
	result = apply_flags(format, (long long)pointer);
	result.length = ft_strlen(result.output);
	result.free = TRUE;
	return (result);
}
