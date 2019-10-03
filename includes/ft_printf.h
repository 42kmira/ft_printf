/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:09:42 by kmira             #+#    #+#             */
/*   Updated: 2019/08/28 23:46:02 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** HEADERS
*/

# include <stdarg.h>
# include <string.h>
# include <unistd.h>

# include "libft.h"
# include "ft_printf_config.h"
# include "color.h"

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** MACROS
*/

# define FORMAT 0
# define OUTPUT 1

# define NULL_TERM 0

# ifndef EXIT
#  define EXIT(error_msg) ft_puterror(error_msg)
# endif

int			ft_printf(char const *format, ...);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: args_tools.c
** Handles things dealing with va_args, like fetching size arguement
*/

int			get_argument_size(int specifier, int length);
void		set_specifier_handler(t_spec_functs *funct, const char *specifier);
t_string	do_function
(t_spec_functs *funct, int arg_size, t_format *format, va_list args);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: conversion_parser.c
** Deals with extracting and parsing the modifiers and specifier into struct
** t_format from a given string.
*/

t_format	extract_format(const char *format_string, size_t *index);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: apply_flags.c
** Uses the flags in the struct t_format.
*/

void		apply_flags_part_2
			(t_format *format, t_string *result, long long value, int sign);
void		apply_flags_part_3
			(t_format *format, t_string *result, long long value, int sign);

void		make_number(uintmax_t num, char *symb, size_t base, t_string *dst);
void		override_flags(t_format *format);
char		*combine_padding(char *string, t_format *format);
void		buffer_fix(char **buffer, int exp);

uintmax_t	signed_mask_p(int signed_bit);
void		precision_padding(t_format *format, t_string *dst);
uintmax_t	correct_number(uintmax_t val, int signed_bit, int len, int *sign);
void		normalize_float(t_string *string);
t_string	make_float_number
			(t_format *form, long double val, char **buff, int *sign);
void		handle_float_flags(t_format *format, t_string *string, int sign);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** DIRECTORY: conversions
** Directory that has the files to handle the different conversions.
*/

t_string	c_handler(t_format *format, int c);
t_string	s_handler(t_format *format, char *string);
t_string	p_handler(t_format *format, void *pointer);
t_string	d_handler(t_format *format, long long value);
t_string	i_handler(t_format *format, long long value);
t_string	u_handler(t_format *format, unsigned long long value);
t_string	b_handler(t_format *format, unsigned long long value);
t_string	x_handler(t_format *format, unsigned long long value);
t_string	o_handler(t_format *format, unsigned long long value);
t_string	f_handler_double(t_format *format, double value);
t_string	f_handler_long(t_format *format, long double value);
t_string	perc_handler(t_format *format, ...);

#endif
