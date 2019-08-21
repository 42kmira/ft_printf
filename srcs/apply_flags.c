/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:03:10 by kmira             #+#    #+#             */
/*   Updated: 2019/08/21 03:17:45 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		precision_padding(t_format *format, t_string *dst)
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

/*
** Here we have to turn the number positive if the signed bit is turned on.
** Positive and negative numbers have different bit signatures (see two's
** complement).
** However in order to do this we have to either multiply by -1 or using
** 2's complement do `val = ~(val) + 1`.
** However note that doing this will also affect the other bits in the number,
** that go beyond the the bit length of the number. This causes an error in the
** number that we have to selectively correct. In order to fix this
** we have a 'filter' mask that only allows the bits within the correct
** bit length to pass through, resulting in the correct positive number.
*/

uintmax_t	correct_number(uintmax_t val, int signed_bit, int length, int *sign)
{
	uintmax_t	mask;

	*sign = 0;
	mask = signed_mask_p(length);
	if (signed_bit >= 0)
		if (val & (1ULL << (signed_bit * 8 - 1)))
		{
			*sign = 1;
			val = ~(val) + 1;
		}
	val = val & mask;
	return (val);
}

char		*combine_padding(char *string, t_format *format)
{
	size_t	length_b;
	size_t	offset;
	size_t	i;
	char	*padding;

	length_b = ft_strlen(string);
	if ((size_t)format->width > length_b)
	{
		padding = malloc(sizeof(*padding) * (format->width + 1));
		ft_bzero(padding, format->width + 1);
		ft_memset(padding, ' ', format->width);
		if (format->flags & ZERO_FLAG)
			ft_memset(padding, '0', format->width);
		i = 0;
		offset = (format->width - length_b);
		if (format->flags & MINUS_FLAG)
			offset = 0;
		while (i < length_b)
		{
			padding[i + offset] = string[i];
			i++;
		}
		free(string);
		return (padding);
	}
	return (string);
}

void		apply_flags_part_2(t_format *format, t_string *result, long long val, int sign)
{
	ft_strrev(result->output);
	if (format->precision == 0 && val == 0)
		result->output[0] = '\0';
	result->length = ft_strlen(result->output);
	if (format->specifier[0] == 'p')
		result->output = ft_append("0x", result->output, FREE_LEFT);
	if (format->flags & HASH_FLAG && val != 0 && !(format->flags & ZERO_FLAG) &&
		(format->specifier[0] == 'x' || format->specifier[0] == 'X'))
		result->output = ft_append("0x", result->output, FREE_LEFT);
	if (!(format->flags & ZERO_FLAG) || format->width - 1 <= result->length)
	{
		if (format->flags & HASH_FLAG && (format->specifier[0] == 'o'))
			if (result->output[0] != '0')
				result->output = ft_append("0", result->output, FREE_LEFT);
		if (sign)
			result->output = ft_append("-", result->output, FREE_LEFT);
		else if (format->flags & PLUS_FLAG)
			result->output = ft_append("+", result->output, FREE_LEFT);
		else if (format->flags & SPACE_FLAG)
			result->output = ft_append(" ", result->output, FREE_LEFT);
		result->length = ft_strlen(result->output);
	}
	result->output = combine_padding(result->output, format);
}

void		apply_flags_part_3(t_format *format, t_string *result, long long value, int sign)
{
	if (format->flags & ZERO_FLAG)
	{
		if (sign)
			result->output[0] = '-';
		else if (format->flags & PLUS_FLAG)
			result->output[0] = '+';
		else if (format->flags & SPACE_FLAG)
			result->output[0] = ' ';
		if (format->flags & HASH_FLAG && value != 0)
		{
			if (format->specifier[0] == 'o')
				if (result->output[0] != '0')
					result->output = ft_append("0", result->output, FREE_LEFT);
			if (format->specifier[0] == 'x' || format->specifier[0] == 'X')
			{
				if (result->output[0] == '0')
					result->output[1] = 'x';
				else
					result->output = ft_append("0x", result->output, FREE_LEFT);
			}
		}
	}
}
