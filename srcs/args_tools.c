/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 19:32:48 by kmira             #+#    #+#             */
/*   Updated: 2019/07/12 16:19:28 by kmira            ###   ########.fr       */
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

#define ARG_SIZE_1 va_arg(args, int)
#define ARG_SIZE_2 va_arg(args, int)
#define ARG_SIZE_4 va_arg(args, int)
#define ARG_SIZE_8 va_arg(args, long long)
#define ARG_SIZE_9 va_arg(args, double)
#define ARG_SIZE_16 va_arg(args, long double)

#define SIZE_1(x) if (x == 1) {return (function->function(format, ARG_SIZE_1));}
#define SIZE_2(x) if (x == 2) {return (function->function(format, ARG_SIZE_2));}
#define SIZE_4(x) if (x == 4) {return (function->function(format, ARG_SIZE_4));}
#define SIZE_8(x) if (x == 8) {return (function->function(format, ARG_SIZE_8));}
#define SIZE_9(x) if (x == 9) {return (function->function(format, ARG_SIZE_9));}
#define SIZE_16(x) if (x == 16) {return (function->function(format, ARG_SIZE_16));}

char	*do_function(t_polymorphous_functions *function, int arguement_size, t_format *format, va_list args)
{
	SIZE_1(arguement_size);
	SIZE_2(arguement_size);
	SIZE_4(arguement_size);
	SIZE_8(arguement_size);
	SIZE_9(arguement_size);
	SIZE_16(arguement_size);
	return (function->function(format));
}
