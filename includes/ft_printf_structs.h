/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 19:02:30 by kmira             #+#    #+#             */
/*   Updated: 2019/08/28 23:53:29 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCTS_H
# define FT_PRINTF_STRUCTS_H

# define N_LENGTH_TYPES 6

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
	int					length;
	int					free;
}						t_string;

typedef struct			s_length
{
	char				*str;
	int					length;
}						t_length;

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
