/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:57:38 by kmira             #+#    #+#             */
/*   Updated: 2019/07/19 16:49:52 by kmira            ###   ########.fr       */
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
	if (signed_bit != 0)
	{
		mask = signed_mask_p(length);
		*sign = (value & (1ULL << (signed_bit * 8 - 1))) ? 1 : 0;
		if (*sign)
		{
			value = value * -1 - 1;
			value = value & mask;
			value = value + 1;
		}
	}
	return (value);
}

void		override_flags(t_format *format)
{
	if (format->precision != -1 || format->flags & MINUS_FLAG)
		format->flags = format->flags & ~ZERO_FLAG;
	if (format->flags & PLUS_FLAG)
		format->flags = format->flags & ~SPACE_FLAG;
}

char		*append(char *a, char *b)
{
	char	*result;
	size_t	length_a;
	size_t	length_b;
	size_t	i;

	length_a = ft_strlen(a);
	length_b = ft_strlen(b);
	result = malloc(sizeof(*result) * (length_a + length_b + 1));
	i = 0;
	while (i < length_a)
	{
		result[i] = a[i];
		i++;
	}
	while (i - length_a < length_b)
	{
		result[i] = b[i - length_a];
		i++;
	}
	return (result);
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

	arg_size = get_arguement_size(format->specifier[0], format->length);
	precision_padding(format, &result);
	value = correct_number(value, arg_size, arg_size, &sign);
	make_number(value, NUM_SET, 10, &result);
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
	}
	return (result);
}

t_string	d_handler(t_format *format, long long value)
{
	t_string	result;

	// result = apply_flags(format, value);
	result.output = "42";
	result.length = ft_strlen(result.output);
	result.free = TRUE;
	(void)format;
	(void)value;
	return (result);
}
