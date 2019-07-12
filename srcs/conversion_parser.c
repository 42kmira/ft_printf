/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 11:17:49 by kmira             #+#    #+#             */
/*   Updated: 2019/07/12 14:08:22 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int g_flag_table[N_FLAGS][2];

int			extract_flags(const char *format_string, size_t *index)
{
	size_t	i;
	int		result;

	i = 0;
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

int		extract_length(const char *format_string, size_t *index)
{
	*index = *index + 2;
	if (format_string[*index - 2] == 'h' && format_string[*index - 1] == 'h')
		return (HH);
	else if (format_string[*index - 2] == 'l' && format_string[*index - 1] == 'l')
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

	format.width = 0;
	format.precision = 0;

	format.length = extract_length(format_string, index);

	format.specifier = &format_string[*index];
	return (format);
}
