/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:03:10 by kmira             #+#    #+#             */
/*   Updated: 2019/08/17 17:19:19 by kmira            ###   ########.fr       */
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

void		make_number(uintmax_t numb, char *symb, size_t base, t_string *dst)
{
	size_t	i;

	i = 0;
	if (numb == 0)
		dst->output[i] = '0';
	while (numb > 0)
	{
		dst->output[i] = symb[numb % base];
		numb = numb / base;
		i++;
	}
}

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
		{
			val = val * -1 - 1;
			val = val + 1;
		}
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
