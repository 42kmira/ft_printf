/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 20:55:14 by kmira             #+#    #+#             */
/*   Updated: 2019/08/22 02:38:34 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

void		round_float(t_format *format, t_string *string)
{
	int	i;
	int	round_begin;
	int carry;

	i = 0;
	while (string->output[i] != '\0' && string->output[i] != '.')
		i++;
	round_begin = i + format->precision + 1;
	carry = 0;
	if (string->output[round_begin] >= '5')
		carry = 1;
	round_begin = round_begin - 1;
	while (round_begin != 0 && carry == 1)
	{
		carry = 0;
		if (string->output[round_begin] == '.')
			round_begin--;
		if (string->output[round_begin] == '9' && ++carry)
			string->output[round_begin] = '0';
		else
			string->output[round_begin] = string->output[round_begin] + 1;
		round_begin--;
	}
}

void		use_flags(t_format *format, t_string *string, int sign)
{
	if (string->output[0] == '.')
		string->output = ft_append("0", string->output, FREE_RIGHT);
	if (format->flags & MINUS_FLAG)
		format->flags = format->flags & ~ZERO_FLAG;
	if (format->flags & ZERO_FLAG && (format->flags & PLUS_FLAG || sign))
		format->width = format->width - 1;
	if (!(format->flags & ZERO_FLAG))
	{
		if (sign == 1)
			string->output = ft_append("-", string->output, FREE_RIGHT);
		else if (format->flags & PLUS_FLAG)
			string->output = ft_append("+", string->output, FREE_RIGHT);
		else if (format->flags & SPACE_FLAG)
			string->output = ft_append(" ", string->output, FREE_RIGHT);
		string->length = ft_strlen(string->output);
	}
}

void		float_padding(t_format *format, t_string *string, int sign)
{
	char	*padding_ptr;

	padding_ptr = malloc(sizeof(*padding_ptr) * (format->width + 1));
	ft_bzero(padding_ptr, format->width + 1);
	string->output = combine_padding(string->output, format);
	if (format->flags & ZERO_FLAG)
	{
		if (sign == 1)
			string->output = ft_append("-", string->output, FREE_RIGHT);
		else if (format->flags & PLUS_FLAG)
			string->output = ft_append("+", string->output, FREE_RIGHT);
		else if (format->flags & SPACE_FLAG && string->output[0] == '0'
				&& string->output[1] == '0')
			string->output[0] = ' ';
		else if (format->flags & SPACE_FLAG)
			string->output = ft_append(" ", string->output, FREE_RIGHT);
	}
}

void		handle_float_flags(t_format *format, t_string *string, int sign)
{
	int		j;
	int		i;

	j = 0;
	while (string->output[j] != '\0' && string->output[j] != '.')
		j++;
	if (format->precision != 0 && string->output[j] != '.')
		string->output[j] = '.';
	j++;
	i = -1;
	while (++i < format->precision)
		if (string->output[i + j] == '\0')
			string->output[i + j] = '0';
	round_float(format, string);
	string->output[j + i] = '\0';
	if (string->output[j + i - 1] == '.' && !(format->flags & HASH_FLAG))
		string->output[j + i - 1] = '\0';
	use_flags(format, string, sign);
	float_padding(format, string, sign);
}

/*
** The 1023 would be bias in the exponent for a double, the 54 would be
** the length of the mantissa. The total is in theory the largest buffer
** needed to store the largest number.
** It might also be incorrect.
** This however does not account for width size or big precision size.
*/

t_string	f_handler_double(t_format *format, double value)
{
	t_string	result;
	char		*buffer;
	int			sign;

	buffer = malloc(sizeof(*buffer) * (format->precision + 1023 + 54));
	ft_bzero(buffer, format->precision + 1023 + 54);
	result = make_float_number(format, value, &buffer, &sign);
	result.length = ft_strlen(result.output);
	if (format->precision == -1)
		format->precision = 6;
	normalize_float(&result);
	handle_float_flags(format, &result, sign);
	result.length = ft_strlen(result.output);
	return (result);
}
