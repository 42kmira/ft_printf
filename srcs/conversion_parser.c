/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 11:17:49 by kmira             #+#    #+#             */
/*   Updated: 2019/08/19 02:24:49 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int g_flag_table[N_FLAGS][2];

int			extract_flags(const char *format_string, size_t *index)
{
	size_t	i;
	int		result;

	i = 0;
	result = 0;
	while (g_flag_table[i][1] != NON_FLAG)
	{
		if (g_flag_table[i][0] == format_string[*index])
		{
			result = result | g_flag_table[i][1];
			*index = *index + 1;
			i = 0;
		}
		else
			i++;
	}
	return (result);
}

int			extract_number(const char *format, size_t *index)
{
	int result;

	result = 0;
	while (ft_isdigit(format[*index]))
	{
		result = result * 10 + (format[*index] - '0');
		*index = *index + 1;
	}
	return (result);
}

int			extract_precision(const char *format_string, size_t *index)
{
	if (format_string[*index] == '.')
	{
		*index = *index + 1;
		return (extract_number(format_string, index));
	}
	else
		return (-1);
}

int			extract_length(const char *format_string, size_t *index)
{
	*index = *index + 2;
	if (format_string[*index - 2] == 'h' && format_string[*index - 1] == 'h')
		return (HH);
	else if (format_string[*index - 2] == 'l'
			&& format_string[*index - 1] == 'l')
		return (LL);
	*index = *index - 1;
	if (format_string[*index - 1] == 'h')
		return (H);
	else if (format_string[*index - 1] == 'l')
		return (L);
	else if (format_string[*index - 1] == 'L')
		return (XL);
	*index = *index - 1;
	return (_DEF_);
}

t_format	extract_format(const char *format_string, size_t *index)
{
	t_format	format;

	format.flags = extract_flags(format_string, index);
	format.width = extract_number(format_string, index);
	format.precision = extract_precision(format_string, index);
	format.length = extract_length(format_string, index);
	format.specifier = &format_string[*index];
	override_flags(&format);
	if (format.length == XL && format.specifier[0] == 'f')
		format.specifier = "F";
	return (format);
}
