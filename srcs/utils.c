/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:40:12 by kmira             #+#    #+#             */
/*   Updated: 2019/08/19 02:14:31 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*append(char *a, char *b, char str_free)
{
	char	*result;

	result = ft_strjoin(a, b);
	if (str_free < 0 || str_free > BOTH)
		ft_puterror("Wrong free option: "__FILE__);
	if (str_free == RIGHT)
		free(a);
	else if (str_free == LEFT)
		free(b);
	else if (str_free == BOTH)
	{
		free(a);
		free(b);
	}
	return (result);
}

void		upper_case_string(char *string)
{
	size_t	i;

	i = 0;
	while (string[i] != '\0')
	{
		string[i] = ft_toupper(string[i]);
		i++;
	}
}

void		override_flags(t_format *format)
{
	if (format->specifier[0] != 'f')
	{
		if (format->precision != -1 || format->flags & MINUS_FLAG)
			format->flags = format->flags & ~ZERO_FLAG;
		if (format->flags & PLUS_FLAG)
			format->flags = format->flags & ~SPACE_FLAG;
	}
}

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
