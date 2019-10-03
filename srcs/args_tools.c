/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 19:32:48 by kmira             #+#    #+#             */
/*   Updated: 2019/08/29 21:54:53 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern int g_type_table[N_SPECIFIERS][9];
extern t_funct g_function_table[N_SPECIFIERS];

#define SPECIFIER 0

int			get_argument_size(int specifier, int length)
{
	int i;

	i = 0;
	if (specifier == 'F' && length == XL)
		return (g_type_table[7][length]);
	while (g_type_table[i][SPECIFIER] != NULL_TERM)
	{
		if (g_type_table[i][SPECIFIER] == specifier)
			return (g_type_table[i][length]);
		i++;
	}
	if (g_type_table[i][SPECIFIER] == NULL_TERM)
		write(1, RED"SPECIFIER does not exist\n"COLOR_RESET, 35);
	return (-1);
}

void		set_specifier_handler(t_spec_functs *function, const char *spec)
{
	int i;

	i = 0;
	if (spec[0] == 'F')
		*function = (t_spec_functs)f_handler_long;
	while (g_function_table[i].specifier != 0)
	{
		if (g_function_table[i].specifier == spec[0])
			*function = (t_spec_functs)g_function_table[i].function;
		i++;
	}
}

#define ARG_SIZE_1 va_arg(args, uint32_t)
#define ARG_SIZE_2 va_arg(args, uint32_t)
#define ARG_SIZE_4 va_arg(args, uint32_t)
#define ARG_SIZE_8 va_arg(args, uint64_t)
#define ARG_SIZE_9 va_arg(args, double)
#define ARG_SIZE_16 va_arg(args, long double)

/*
** Based on the function that was set by set_specifier_handler()
** the do_function() will return the resulting t_string.
** The arguements passed into the handler function are the `format`
** and a macro that expands to the correct `va_arg()`. The correct
** va_arg() is determined by the byte length that was passed in as
** arg_size (calcuated by a combination of the specifier and the
** length modifier, see `g_type_table[N_SPECIFIERS][9]`).
*/

#define SIZE_0(x) if (x == 1) {return (funct->function(format));}
#define SIZE_1(x) if (x == 1) {return (funct->function(format, ARG_SIZE_1));}
#define SIZE_2(x) if (x == 2) {return (funct->function(format, ARG_SIZE_2));}
#define SIZE_4(x) if (x == 4) {return (funct->function(format, ARG_SIZE_4));}
#define SIZE_8(x) if (x == 8) {return (funct->function(format, ARG_SIZE_8));}
#define SIZE_9(x) if (x == 9) {return (funct->function(format, ARG_SIZE_9));}
#define SIZE_16(x) if (x == 16) {return (funct->function(format, ARG_SIZE_16));}

t_string	do_function
	(t_spec_functs *funct, int arg_size, t_format *format, va_list args)
{
	SIZE_1(arg_size);
	SIZE_2(arg_size);
	SIZE_4(arg_size);
	SIZE_8(arg_size);
	SIZE_9(arg_size);
	SIZE_16(arg_size);
	SIZE_0(arg_size);
	return (funct->function(format));
}
