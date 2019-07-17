/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 19:02:30 by kmira             #+#    #+#             */
/*   Updated: 2019/07/17 12:04:26 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCTS_H
# define FT_PRINTF_STRUCTS_H

enum	e_type_size
{
	NO_TYPE = -1,
    INT     = sizeof(int),
    U_INT   = sizeof(unsigned int),
    S_CHAR  = sizeof(signed char),
    U_CHAR  = sizeof(unsigned char),
    SHORT   = sizeof(short),
    U_SHORT = sizeof(unsigned short),
    LONG    = sizeof(long),
    U_LONG  = sizeof(unsigned long),
    LLONG   = sizeof(long long),
    U_LLONG = sizeof(unsigned long long),
    DOUB    = sizeof(double),
    L_DOUB  = sizeof(long double),
    STR     = sizeof(char *),
    VOID_P  = sizeof(void *)
};

# define N_LENGTH_TYPES 6

enum	e_length_types
{
    _DEF_     = 1,
    HH        = 2,
    H         = 3,
    L         = 4,
    LL        = 5,
    XL        = 6
};

# define N_FLAGS 6

enum	e_printf_flags
{
    NON_FLAG   = 0b00000,
    MINUS_FLAG = 0b00001,
    PLUS_FLAG  = 0b00010,
    SPACE_FLAG = 0b00100,
    HASH_FLAG  = 0b01000,
    ZERO_FLAG  = 0b10000
};

typedef struct	s_format
{
	int			flags;
	int			width;
	int			precision;
	int			length;
	const char	*specifier;
}				t_format;

typedef struct	s_string
{
	char		*output;
	char		single[1];
	int			length;
	int			free;
}				t_string;

typedef union	u_polymorphous_functions
{
	t_string	(*function)(t_format *format, ...);
	t_string	(*c_handler)(t_format *format, int c);
	t_string	(*s_handler)(t_format *format, char *string);
	t_string	(*p_handler)(t_format *format, void *pointer);
	t_string	(*d_handler)(t_format *format, long long value);
	t_string	(*u_handler)(t_format *format, unsigned long long value);
	t_string	(*x_handler)(t_format *format, unsigned long long value);
	t_string	(*o_handler)(t_format *format, unsigned long long value);
	t_string	(*f_handler)(t_format *format, long double value);
	t_string	(*perc_handler)(t_format *format, ...);
}				t_polymorphous_functions;

#endif
