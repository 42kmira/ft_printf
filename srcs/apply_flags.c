/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:03:10 by kmira             #+#    #+#             */
/*   Updated: 2019/07/25 04:58:58 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	signed_mask_p(int signed_bit)
{
	long long	mask;
	int			i;

	i = 0;
	mask = 0;
	while (i < signed_bit)
	{
		mask = mask << 8;
		mask = mask | 0b11111111;
		i++;
	}
	return (mask);
}

void	make_number(uintmax_t number, char *symbols, size_t base, t_string *dst)
{
	size_t	i;

	i = 0;
	if (number == 0)
		dst->output[i] = '0';
	while (number > 0)
	{
		dst->output[i] = symbols[number % base];
		number = number / base;
		i++;
	}
}

void	precision_padding(t_format *format, t_string *dst)
{
	size_t	length;

	if (format->precision > (int)sizeof(uintmax_t) * 8)
		length = format->precision + 1;
	else
		length = sizeof(uintmax_t) * 8 + 1;
	dst->output = malloc(sizeof(*(dst->output)) * (length));
	ft_bzero(dst->output, length);
	dst->free = TRUE;
	if (format->precision > 0)
		ft_memset(dst->output, '0', format->precision);
}

uintmax_t	correct_number(uintmax_t value, int signed_bit, int length, int *sign)
{
	uintmax_t	mask;

	*sign = 0;
	mask = signed_mask_p(length);
	if (signed_bit != 0)
	{
		*sign = (value & (1ULL << (signed_bit * 8 - 1))) ? 1 : 0;
		if (*sign)
		{
			value = value * -1 - 1;
			value = value + 1;
		}
	}
	value = value & mask;
	return (value);
}

void		override_flags(t_format *format)
{
	if (format->precision != -1 || format->flags & MINUS_FLAG)
		format->flags = format->flags & ~ZERO_FLAG;
	if (format->flags & PLUS_FLAG)
		format->flags = format->flags & ~SPACE_FLAG;
}

char	*combine_padding(char *padding, char *string, int left_align)
{
	size_t	length_a;
	size_t	length_b;
	size_t	i;
	size_t	offset;

	length_a = ft_strlen(padding);
	length_b = ft_strlen(string);
	if (length_a > length_b)
	{
		i = 0;
		offset = (length_a - length_b);
		if (left_align)
			offset = 0;
		while (i < length_b)
		{
			padding[i + offset] = string[i];
			i++;
		}
		return (padding);
	}
	return (string);
}

t_string	apply_flags(t_format *format, long long value)
{
	t_string	result;
	int			arg_size;
	int			sign;
	int			base;
	int			length;

	arg_size = get_arguement_size(format->specifier[0], format->length);
	length = 0;
	if (format->specifier[0] == 'o' || format->specifier[0] == 'O')
		base = 8;
	else if (format->specifier[0] == 'x' || format->specifier[0] == 'X' || format->specifier[0] == 'p')
		base = 16;
	else
	{
		base = 10;
		length = arg_size;
	}
	precision_padding(format, &result);
	value = correct_number(value, length, arg_size, &sign);
	make_number(value, NUM_SET, base, &result);
	ft_strrev(result.output);
	if (format->precision == 0 && value == 0)
		result.output[0] = '\0';
	result.length = ft_strlen(result.output);
	override_flags(format);
	if (!(format->flags & ZERO_FLAG) || format->width - 1 <= result.length)
	{
		if (sign)
			result.output = append("-", result.output);
		else if (format->flags & PLUS_FLAG)
			result.output = append("+", result.output);
		else if (format->flags & SPACE_FLAG)
			result.output = append(" ", result.output);

		if (value > 0)
		{
			if (format->flags & HASH_FLAG && (format->specifier[0] == 'o' || format->specifier[0] == 'O'))
				result.output = append("0", result.output);
			else if (format->flags & HASH_FLAG && (format->specifier[0] == 'x' || format->specifier[0] == 'X'))
				result.output = append("0x", result.output);
		}
		result.length = ft_strlen(result.output);
	}
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
	if (format->flags & ZERO_FLAG)
	{
		if (sign)
			result.output[0] = '-';
		else if (format->flags & PLUS_FLAG)
			result.output[0] = '+';
		else if (format->flags & SPACE_FLAG)
			result.output[0] = ' ';

		if (format->flags & HASH_FLAG && (format->specifier[0] == 'o' || format->specifier[0] == 'O'))
			result.output = append("0", result.output);
		if (format->flags & HASH_FLAG && (format->specifier[0] == 'x' || format->specifier[0] == 'X'))
			result.output = append("0x", result.output);
	}
	return (result);
}
