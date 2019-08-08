/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 19:02:30 by kmira             #+#    #+#             */
/*   Updated: 2019/08/07 22:20:34 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCTS_H
# define FT_PRINTF_STRUCTS_H

enum				e_type_size
{
	NO_TYPE = -1,
	CHAR = sizeof(char),
	INT = sizeof(int),
	U_INT = sizeof(unsigned int),
	S_CHAR = sizeof(signed char),
	U_CHAR = sizeof(unsigned char),
	SHORT = sizeof(short),
	U_SHOR = sizeof(unsigned short),
	LONG = sizeof(long),
	U_LONG = sizeof(unsigned long),
	LLONG = sizeof(long long),
	U_LLON = sizeof(unsigned long long),
	DOUB = sizeof(double) + 1,
	L_DOUB = sizeof(long double),
	STR = sizeof(char *),
	VOID_P = sizeof(void *)
};

# define N_LENGTH_TYPES 6

enum					e_length_types
{
	_DEF_ = 1,
	HH = 2,
	H = 3,
	L = 4,
	LL = 5,
	XL = 6
};

# define N_FLAGS 6

enum					e_printf_flags
{
	NON_FLAG = 0b00000,
	MINUS_FLAG = 0b00001,
	PLUS_FLAG = 0b00010,
	SPACE_FLAG = 0b00100,
	HASH_FLAG = 0b01000,
	ZERO_FLAG = 0b10000
};

typedef struct			s_format
{
	int					flags;
	int					width;
	int					precision;
	int					length;
	const char			*specifier;
}						t_format;

typedef struct			s_string
{
	char				*output;
	char				single[1];
	int					length;
	int					free;
}						t_string;

typedef union			u_spec_functs
{
	t_string			(*function)(t_format *format, ...);
	t_string			(*c_handler)(t_format *format, int c);
	t_string			(*s_handler)(t_format *format, char *string);
	t_string			(*p_handler)(t_format *format, void *pointer);
	t_string			(*d_handler)(t_format *format, long long value);
	t_string			(*u_handler)(t_format *format, unsigned long long val);
	t_string			(*x_handler)(t_format *format, unsigned long long val);
	t_string			(*o_handler)(t_format *format, unsigned long long val);
	t_string			(*f_handler_double)(t_format *format, double);
	t_string			(*f_handler_long)(t_format *format, long double);
	t_string			(*perc_handler)(t_format *format, ...);
}						t_spec_functs;

union					u_ieee2_d
{
	double				type;
	struct
	{
		unsigned long	mantissa	: 52;
		unsigned int	exp			: 11;
		unsigned int	sign		: 1;
	}					bits;
}						u_double_bit;

union					u_ieee2_ld
{
	long double			type;
	struct
	{
		unsigned long	mantissa	:64;
		unsigned int	exp			:15;
		unsigned int	sign		:1;
	}					bits;

}						u_long_double_bit;

union					u_ieee2bits
{
	union u_ieee2_d		double_;
	union u_ieee2_ld	long_double_;
}						u_iee2bits;

#endif
