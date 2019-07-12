/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 19:02:30 by kmira             #+#    #+#             */
/*   Updated: 2019/07/11 21:33:18 by kmira            ###   ########.fr       */
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

enum	e_length_types
{
    NO_LENGTH = -1,
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

typedef union	u_polymorphous_functions
{
	char		*(*function)(t_format *format, ...);
	char		*(*c_specifier)(t_format *format, char c);
	char		*(*s_specifier)(t_format *format, char *string);
	char		*(*p_specifier)(t_format *format, void *pointer);
	char		*(*i_specifier)(t_format *format, int i);
	char		*(*perc_specifier)(t_format *format, ...);
}				t_polymorphous_functions;

#endif
