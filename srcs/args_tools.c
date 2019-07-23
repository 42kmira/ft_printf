/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 19:32:48 by kmira             #+#    #+#             */
/*   Updated: 2019/07/23 15:06:23 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int g_type_table[N_SPECIFIERS][9];

#define SPECIFIER 0

int			get_arguement_size(int specifier, int length)
{
	int i;

	i = 0;
	while (g_type_table[i][SPECIFIER] != NULL_TERM)
	{
		if (g_type_table[i][SPECIFIER] == ft_tolower(specifier))
			return (g_type_table[i][length]);
		i++;
	}
	if (g_type_table[i][SPECIFIER] == NULL_TERM)
		write(1, RED"SPECIFIER does not exist\n"COLOR_RESET, 32);
	return (-1);
}

void		set_specifier_handler(t_polymorphous_functions *function, const char *specifier)
{
	if (specifier[0] == 'c')
		function->c_handler = c_handler;
	if (specifier[0] == 's')
		function->s_handler = s_handler;
	if (specifier[0] == 'p')
		function->p_handler = p_handler;
	if (specifier[0] == 'd')
		function->d_handler = d_handler;
	if (specifier[0] == 'i')
		function->d_handler = i_handler;
	if (specifier[0] == 'u')
		function->u_handler = u_handler;
	if (specifier[0] == 'x' || specifier[0] == 'X')
		function->x_handler = x_handler;
	if (specifier[0] == 'o' || specifier[0] == 'O')
		function->o_handler = o_handler;
	if (specifier[0] == 'f')
		function->f_handler_double = f_handler_double;
	if (specifier[0] == 'F')
		function->f_handler_long = f_handler_long;
	if (specifier[0] == '%')
		function->perc_handler = perc_handler;
}

#define ARG_SIZE_1 (char)va_arg(args, int)
#define ARG_SIZE_2 (short)va_arg(args, int)
#define ARG_SIZE_4 va_arg(args, int)
#define ARG_SIZE_8 va_arg(args, long long)
#define ARG_SIZE_9 (double)va_arg(args, double)
#define ARG_SIZE_16 (long double)va_arg(args, long double)

#define SIZE_1(x) if (x == 1) {return (function->function(format, ARG_SIZE_1));}
#define SIZE_2(x) if (x == 2) {return (function->function(format, ARG_SIZE_2));}
#define SIZE_4(x) if (x == 4) {return (function->function(format, ARG_SIZE_4));}
#define SIZE_8(x) if (x == 8) {return (function->function(format, ARG_SIZE_8));}
#define SIZE_9(x) if (x == 9) {return (function->function(format, ARG_SIZE_9));}
#define SIZE_16(x) if (x == 16) {return (function->function(format, ARG_SIZE_16));}

t_string	do_function(t_polymorphous_functions *function, int arguement_size, t_format *format, va_list args)
{
	SIZE_1(arguement_size);
	SIZE_2(arguement_size);
	SIZE_4(arguement_size);
	SIZE_8(arguement_size);
	SIZE_9(arguement_size);
	SIZE_16(arguement_size);
	return (function->function(format));
}
