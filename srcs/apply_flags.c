/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:03:10 by kmira             #+#    #+#             */
/*   Updated: 2019/08/07 23:43:39 by kmira            ###   ########.fr       */
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
	if (mask == 0)
		return (1);
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
