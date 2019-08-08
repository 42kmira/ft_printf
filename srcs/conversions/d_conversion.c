/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:57:38 by kmira             #+#    #+#             */
/*   Updated: 2019/08/07 22:27:33 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

/*
** FLAGS:
** 		VALID FLAGS: -+ 0
** 			VALID FLAGS: 4/5
** 		INVALID FLAGS: #
** 			INVALID FLAGS: 1/5
**
** WIDTH:
** 		Is always applicable.
**
** PRECISION:
** 		For integer specifiers (d, i, o, u, x, X):
**		precision specifies the minimum number of
**		digits to be written. If the value to be written
**		is shorter than this number, the result is padded
**		with leading zeros. The value is not truncated even
**		if the result is longer. A precision of 0 means that
**		no character is written for the value 0.
*/

t_string	d_handler(t_format *format, long long value)
{
	t_string	result;

	result = apply_flags(format, value);
	result.length = ft_strlen(result.output);
	result.free = TRUE;
	(void)format;
	(void)value;
	return (result);
}
