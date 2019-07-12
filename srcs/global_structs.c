/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_structs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 19:35:02 by kmira             #+#    #+#             */
/*   Updated: 2019/07/11 21:19:51 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

enum	e_specifier
{
    SP_D    = 'd',
    SP_I    = 'i',
    SP_U    = 'u',
    SP_O    = 'o',
    SP_X    = 'X',
    SP_F    = 'f',
    SP_C    = 'c',
    SP_S    = 's',
    SP_P    = 'p',
    SP_PERC = '%'
};

int		g_type_table[N_SPECIFIERS][9] =
{
	{-1,	_DEF_,	HH,		H,		L,		LL,		XL},
	{SP_D,	INT,	S_CHAR,	SHORT,	LONG,	LLONG,	-1},
	{SP_I,	INT,	S_CHAR,	SHORT,	LONG,	LLONG,	-1},
	{SP_U,	U_INT,	U_CHAR,	U_SHORT,U_LONG,	U_LLONG,-1},
	{SP_O,	U_INT,	U_CHAR,	U_SHORT,U_LONG,	U_LLONG,-1},
	{SP_X,	U_INT,	U_CHAR,	U_SHORT,U_LONG,	U_LLONG,-1},
	{SP_F,	DOUB,	-1,		-1,		-1,		-1,		L_DOUB},
	{SP_C,	INT,	-1,		-1,		-1,		-1,		-1},
	{SP_S,	STR,	-1,		-1,		-1,		-1,		-1},
	{SP_P,	VOID_P,	-1,		-1,		-1,		-1,		-1},
	{0,		0,		0,		0,		0,		0,		0}
};

int		g_flag_table[N_FLAGS][2] =
{
	{'-', MINUS_FLAG},
	{'+', PLUS_FLAG},
	{' ', SPACE_FLAG},
	{'#', HASH_FLAG},
	{'0', ZERO_FLAG},
	{'\0', NON_FLAG}
};
