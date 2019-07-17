/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 20:57:02 by kmira             #+#    #+#             */
/*   Updated: 2019/07/17 12:04:56 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Pass a buffer that can hold any number which you wish to convert.
** Return the adress. If you need to append the 0x to the front
** you can just go two back in address space and add them there.
** you can make a certain buffer for padding and if the necessary.
** If padding is more then you can enter a slower loop to padd,
** but under other conditions then it padds the number faster.
*/

/*
** Buffer for the entire string?
** Maybe a structure for it that holds the place and maybe
** does the buffer flush if necessary.
*/

t_string	x_handler(t_format *format, unsigned long long value)
{
	t_string	result;
	int			arg_size;

	arg_size = get_arguement_size(format->specifier[0], format->length);
	result.output = ft_ntoa(value, 0, arg_size, NUM_SET, 16);
	result.length = ft_strlen(result.output);
	result.free = TRUE;
	return (result);
}

// t_string	x_handler(t_format *format, unsigned long long value)
// {
// 	t_string	result;
// 	int			arg_size;
// 	char		*buffer[PADDING_SIZE + BINARY_MAX_LENGTH + END_PADDING];

// 	arg_size = get_arguement_size(format->specifier[0], format->length);
// 	result.output = ft_ntoa(value, 0, arg_size, NUM_SET, 16);
// 	result.length = ft_strlen(result.output);
// 	result.free = TRUE;
// 	return (result);
// }