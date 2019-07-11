/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 16:38:24 by kmira             #+#    #+#             */
/*   Updated: 2019/07/10 10:21:39 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puterror(char const *s)
{
	if (s == NULL)
		return ;
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}
