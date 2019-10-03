/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_config.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 23:41:50 by kmira             #+#    #+#             */
/*   Updated: 2019/08/29 22:58:17 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CONFIG_H
# define FT_PRINTF_CONFIG_H

# include "ft_printf_structs.h"

enum				e_length_types
{
	_DEF_ = 1,
	HH = 2,
	H = 3,
	L = 4,
	LL = 5,
	XL = 6
};

static t_length		g_length_table[6] =
{
	{"hh", HH},
	{"h", H},
	{"ll", LL},
	{"l", L},
	{"L", XL},
	{"", _DEF_}
};

enum				e_type_size
{
	NO_TYPE = -1,
	CHAR = sizeof(char),
	INT = sizeof(int),
	U_INT = sizeof(unsigned int),
	S_CHAR = sizeof(signed char),
	U_CHAR = sizeof(unsigned char),
	SHORT = sizeof(short),
	U_SHORT = sizeof(unsigned short),
	LONG = sizeof(long),
	U_LONG = sizeof(unsigned long),
	LLONG = sizeof(long long),
	U_LLONG = sizeof(unsigned long long),
	DOUB = sizeof(double) + 1,
	L_DOUB = sizeof(long double),
	STR = sizeof(char *),
	VOID_P = sizeof(void *)
};

enum				e_specifier
{
	SP_D = 'd',
	SP_I = 'i',
	SP_U = 'u',
	SP_O = 'o',
	SP_X = 'x',
	SP_UX = 'X',
	SP_F = 'f',
	SP_C = 'c',
	SP_S = 's',
	SP_P = 'p',
	SP_PERC = '%',
};

t_string			c_handler(t_format *format, int c);
t_string			s_handler(t_format *format, char *string);
t_string			p_handler(t_format *format, void *pointer);
t_string			d_handler(t_format *format, long long value);
t_string			i_handler(t_format *format, long long value);
t_string			u_handler(t_format *format, unsigned long long value);
t_string			x_handler(t_format *format, unsigned long long value);
t_string			o_handler(t_format *format, unsigned long long value);
t_string			f_handler_double(t_format *format, double value);
t_string			f_handler_long(t_format *format, long double value);
t_string			perc_handler(t_format *format, ...);

typedef union		u_spec_functs
{
	t_string		(*function)(t_format *format, ...);
	t_string		(*c_handler)(t_format *format, int c);
	t_string		(*s_handler)(t_format *format, char *string);
	t_string		(*p_handler)(t_format *format, void *pointer);
	t_string		(*d_handler)(t_format *format, long long val);
	t_string		(*u_handler)(t_format *format, unsigned long long val);
	t_string		(*x_handler)(t_format *format, unsigned long long val);
	t_string		(*o_handler)(t_format *format, unsigned long long val);
	t_string		(*f_handler_double)(t_format *format, double);
	t_string		(*f_handler_long)(t_format *format, long double);
	t_string		(*perc_handler)(t_format *format, ...);
}					t_spec_functs;

typedef struct		s_function
{
	int				specifier;
	t_spec_functs	function;
}					t_funct;

# define N_SPECIFIERS 13

static t_funct		g_function_table[N_SPECIFIERS] =
{
	{SP_D, (t_spec_functs)d_handler},
	{SP_I, (t_spec_functs)d_handler},
	{SP_U, (t_spec_functs)u_handler},
	{SP_O, (t_spec_functs)o_handler},
	{SP_X, (t_spec_functs)x_handler},
	{SP_UX, (t_spec_functs)x_handler},
	{SP_F, (t_spec_functs)f_handler_double},
	{SP_C, (t_spec_functs)c_handler},
	{SP_S, (t_spec_functs)s_handler},
	{SP_P, (t_spec_functs)p_handler},
	{SP_PERC, (t_spec_functs)perc_handler},
	{0, (t_spec_functs)d_handler}
};

static int			g_type_table[N_SPECIFIERS][9] =
{
	{-1, _DEF_, HH, H, L, LL, XL},
	{SP_D, INT, S_CHAR, SHORT, LONG, LLONG, -1},
	{SP_I, INT, S_CHAR, SHORT, LONG, LLONG, -1},
	{SP_U, U_INT, U_CHAR, U_SHORT, U_LONG, U_LLONG, -1},
	{SP_O, U_INT, U_CHAR, U_SHORT, U_LONG, U_LLONG, -1},
	{SP_X, U_INT, U_CHAR, U_SHORT, U_LONG, U_LLONG, -1},
	{SP_UX, U_INT, U_CHAR, U_SHORT, U_LONG, U_LLONG, -1},
	{SP_F, DOUB, -1, -1, DOUB, -1, L_DOUB},
	{SP_C, INT, -1, -1, -1, -1, -1},
	{SP_S, STR, -1, -1, -1, -1, -1},
	{SP_P, VOID_P, -1, -1, -1, -1, -1},
	{SP_PERC, 0, -1, -1, -1, -1, -1},
	{0, 0, 0, 0, 0, 0, 0}
};

# define N_FLAGS 6

enum				e_printf_flags
{
	NON_FLAG = 0b00000,
	MINUS_FLAG = 0b00001,
	PLUS_FLAG = 0b00010,
	SPACE_FLAG = 0b00100,
	HASH_FLAG = 0b01000,
	ZERO_FLAG = 0b10000,
};

static int			g_flag_table[N_FLAGS][2] =
{
	{'-', MINUS_FLAG},
	{'+', PLUS_FLAG},
	{' ', SPACE_FLAG},
	{'#', HASH_FLAG},
	{'0', ZERO_FLAG},
	{'\0', NON_FLAG}
};

#endif
