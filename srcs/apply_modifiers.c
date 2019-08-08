/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_modifiers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:12:35 by kmira             #+#    #+#             */
/*   Updated: 2019/08/07 23:43:29 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string	part_4(t_format	*format, t_string result, long long value, int sign)
{
	if (format->flags & ZERO_FLAG)
	{
		if (sign)
			result.output[0] = '-';
		else if (format->flags & PLUS_FLAG)
			result.output[0] = '+';
		else if (format->flags & SPACE_FLAG)
			result.output[0] = ' ';
		if (format->flags & HASH_FLAG && value != 0)
		{
			if (format->specifier[0] == 'o' || format->specifier[0] == 'O')
				if (result.output[0] != '0')
					result.output = append("0", result.output);
			if (format->specifier[0] == 'x' || format->specifier[0] == 'X')
			{
				if (result.output[0] == '0' && result.output[0] == '0')
					result.output[1] = 'x';
				else
					result.output = append("0x", result.output);
			}
		}
	}
	return (result);
}

t_string		padding(t_format *format, t_string result)
{
	char *padding;

	padding = malloc(sizeof(*padding) * (format->width + 1));
	ft_bzero(padding, format->width + 1);
	if (format->flags & ZERO_FLAG)
		ft_memset(padding, '0', format->width);
	else
		ft_memset(padding, ' ', format->width);
	int minus;
	minus = 0;
	if (format->flags & MINUS_FLAG)
		minus = 1;
	result.output = combine_padding(padding, result.output, minus);
}

void		part_1(t_format *format, t_string *result, long long value, int *sign)
{
	int	length;
	int	arg_size;
	int	base;

	length = 0;
	arg_size = get_arguement_size(format->specifier[0], format->length);
	length = 0;
	base = 10;
	if (format->specifier[0] == 'o' || format->specifier[0] == 'O')
		base = 8;
	else if (format->specifier[0] == 'x' || format->specifier[0] == 'X' || format->specifier[0] == 'p')
		base = 16;
	else
		length = arg_size;
	precision_padding(format, result);
	if (format->specifier[0] == 'u' || format->specifier[0] == 'o' || format->specifier[0] == 'o')
		value = correct_number(value, 0, arg_size, &sign);
	else
		value = correct_number(value, length, arg_size, &sign);
	make_number(value, NUM_SET, base, result);
	ft_strrev(result->output);
}

t_string	apply_flags(t_format *format, long long value)
{
	t_string	result;
	int			arg_size;
	int			sign;
	int			base;

	part_1(format, &result, value, &sign);
	if (format->precision == 0 && value == 0)
		result.output[0] = '\0';
	result.length = ft_strlen(result.output);
	override_flags(format);
	if (format->specifier[0] == 'p')
	{
		result.output = append("0x", result.output);
		result.length = result.length + 2;
	}
	if (value > 0 && !(format->flags & ZERO_FLAG))
		if (format->flags & HASH_FLAG && (format->specifier[0] == 'x' || format->specifier[0] == 'X'))
			result.output = append("0x", result.output);
	if (!(format->flags & ZERO_FLAG) || format->width - 1 <= result.length)
	{
		if (format->flags & HASH_FLAG && (format->specifier[0] == 'o' || format->specifier[0] == 'O'))
			if (result.output[0] != '0')
				result.output = append("0", result.output);
		if (sign)
			result.output = append("-", result.output);
		else if (format->flags & PLUS_FLAG)
			result.output = append("+", result.output);
		else if (format->flags & SPACE_FLAG)
			result.output = append(" ", result.output);

		result.length = ft_strlen(result.output);
	}

	result = padding(format, result);
	result = part_4(format, result, value, sign);
	return (result);
}


