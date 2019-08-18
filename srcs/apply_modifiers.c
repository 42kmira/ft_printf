/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_modifiers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:12:35 by kmira             #+#    #+#             */
/*   Updated: 2019/08/17 17:21:22 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		part_1(t_format *format, t_string *result, long long val, int *sign)
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
	else if (format->specifier[0] == 'x' || format->specifier[0] == 'X'
			|| format->specifier[0] == 'p')
		base = 16;
	else
		length = arg_size;
	precision_padding(format, result);
	if (format->specifier[0] == 'u' || format->specifier[0] == 'o'
			|| format->specifier[0] == 'o')
		val = correct_number(val, 0, arg_size, sign);
	else
		val = correct_number(val, length, arg_size, sign);
	make_number(val, NUM_SET, base, result);
	ft_strrev(result->output);
}

void		part_2(t_format *format, t_string *result, long long val, int *sign)
{
	if (format->specifier[0] == 'p')
	{
		result->output = append("0x", result->output);
		result->length = result->length + 2;
	}
	if (val > 0 && !(format->flags & ZERO_FLAG))
		if (format->flags & HASH_FLAG && (format->specifier[0] == 'x'
			|| format->specifier[0] == 'X'))
			result->output = append("0x", result->output);
	if (!(format->flags & ZERO_FLAG) || format->width - 1 <= result->length)
	{
		if (format->flags & HASH_FLAG && (format->specifier[0] == 'o'
			|| format->specifier[0] == 'O'))
			if (result->output[0] != '0')
				result->output = append("0", result->output);
		if (*sign)
			result->output = append("-", result->output);
		else if (format->flags & PLUS_FLAG)
			result->output = append("+", result->output);
		else if (format->flags & SPACE_FLAG)
			result->output = append(" ", result->output);
		result->length = ft_strlen(result->output);
	}
}

t_string	part_3(t_format *format, t_string result, long long value, int sign)
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

t_string	apply_flags(t_format *format, long long value)
{
	t_string	result;
	int			sign;

	part_1(format, &result, value, &sign);
	if (format->precision == 0 && value == 0)
		result.output[0] = '\0';
	result.length = ft_strlen(result.output);
	override_flags(format);
	part_2(format, &result, value, &sign);
	result.output = combine_padding(result.output, format);
	result = part_3(format, result, value, sign);
	return (result);
}
