/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 19:32:48 by kmira             #+#    #+#             */
/*   Updated: 2019/07/12 14:03:40 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int g_type_table[N_SPECIFIERS][9];

#define SPECIFIER 0

int		get_arguement_size(int specifier, int length)
{
	int i;

	i = 0;
	while (g_type_table[i][SPECIFIER] != NULL_TERM)
	{
		if (g_type_table[i][SPECIFIER] == specifier)
			return (g_type_table[i][length]);
		i++;
	}
	if (g_type_table[i][SPECIFIER] == NULL_TERM)
		EXIT(RED"Could not find this specifier");
	return (-1);
}

void	set_specifier_handler(t_polymorphous_functions *function, const char *specifier)
{
	if (specifier[0] == 's')
		function->s_handler = s_handler;
	if (specifier[0] == 'd' || specifier[0] == 'i')
		function->d_handler = d_handler;
	if (specifier[0] == '%')
		function->perc_handler = perc_handler;
}
