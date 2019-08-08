/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 18:12:14 by kmira             #+#    #+#             */
/*   Updated: 2019/08/01 20:13:35 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORM_H
# define NORM_H

struct			s_norm_type
{
	int	a;
	int	b;
}	t_norms;

struct			s_structy_type
{
	int						a;
	int						b;
	char					c;
	struct s_structy_type	*next;
}	t_stry;

union			u_uns
{
	long	a;
	struct		s_some
	{
		int	a;
		int	b;
	};
};

struct t_norms	function(void);
char			funct(void);

extern int	g_a;

# ifndef SOME
#  define SOME 5
# endif

#endif

/*
**		int sign	: 1;
**		int os		: 4;
**		int midi	: 7;
**		int end		: 7;
*/
