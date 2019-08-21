/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perc_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:32:07 by kmira             #+#    #+#             */
/*   Updated: 2019/08/21 03:28:22 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	perc_handler(t_format *format, ...)
{
	t_string	result;
	size_t		i;
	int			sign;

	format->length = INT;
	sign = 0;
	precision_padding(format, &result);
	make_number(1, NUM_SET, 10, &result);
	apply_flags_part_2(format, &result, 1, sign);
	apply_flags_part_3(format, &result, 1, sign);
	i = 0;
	while (result.output[i] != '\0' && result.output[i] != '1')
		i++;
	if (result.output[i] == '1')
		result.output[i] = '%';
	result.length = ft_strlen(result.output);
	return (result);
}
