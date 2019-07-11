/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 19:32:48 by kmira             #+#    #+#             */
/*   Updated: 2019/07/11 11:17:53 by kmira            ###   ########.fr       */
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
}

void	set_specifier_handler()
{

}
