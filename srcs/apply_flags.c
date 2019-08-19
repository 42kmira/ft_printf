/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:03:10 by kmira             #+#    #+#             */
/*   Updated: 2019/08/19 02:14:41 by kmira            ###   ########.fr       */
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

uintmax_t	correct_number(uintmax_t val, int signed_bit, int length, int *sign)
{
	uintmax_t	mask;

	*sign = 0;
	mask = signed_mask_p(length);
	if (signed_bit != 0)
	{
		*sign = (val & (1ULL << (signed_bit * 8 - 1))) ? 1 : 0;
		if (*sign)
			val = val * -1;
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
		result->output = append("0x", result->output, LEFT);
	if (format->flags & HASH_FLAG && val != 0 && !(format->flags & ZERO_FLAG) &&
		(format->specifier[0] == 'x' || format->specifier[0] == 'X'))
		result->output = append("0x", result->output, LEFT);
	if (!(format->flags & ZERO_FLAG) || format->width - 1 <= result->length)
	{
		if (format->flags & HASH_FLAG && (format->specifier[0] == 'o'))
			if (result->output[0] != '0')
				result->output = append("0", result->output, LEFT);
		if (sign)
			result->output = append("-", result->output, LEFT);
		else if (format->flags & PLUS_FLAG)
			result->output = append("+", result->output, LEFT);
		else if (format->flags & SPACE_FLAG)
			result->output = append(" ", result->output, LEFT);
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
					result->output = append("0", result->output, LEFT);
			if (format->specifier[0] == 'x' || format->specifier[0] == 'X')
			{
				if (result->output[0] == '0')
					result->output[1] = 'x';
				else
					result->output = append("0x", result->output, LEFT);
			}
		}
	}
}
