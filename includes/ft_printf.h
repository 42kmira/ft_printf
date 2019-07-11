/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:09:42 by kmira             #+#    #+#             */
/*   Updated: 2019/07/11 12:44:18 by kmira            ###   ########.fr       */
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
# include "ft_printf_structs.h"
# include "color.h"

# include "debug.h"

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** MACROS
*/

# define FORMAT 0
# define OUTPUT 1

# define N_SPECIFIERS 11

# define NULL_TERM 0

# ifndef EXIT
#  define EXIT(error_msg) ft_puterror(error_msg)
# endif

int	ft_printf(const char *format, ...);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: conversion_parser.c
** Deals with extracting and parsing the modifiers and specifier into struct t_format
** from a given string.
*/

t_format	extract_format(const char *format_string, size_t *index);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** DIRECTORY: conversions
** Directory that has the files to handle the different conversions.
*/

char	*c_handlers(t_format *format, char c);
char	*s_handlers(t_format *format, char *string);
char	*p_handlers(t_format *format, void *pointer);

#endif
