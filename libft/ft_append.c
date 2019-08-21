/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:33:59 by kmira             #+#    #+#             */
/*   Updated: 2019/08/19 18:39:10 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_append(char *right, char *left, char str_free)
{
	char	*result;

	result = ft_strjoin(right, left);
	if (str_free < 0 || str_free > FREE_BOTH)
		ft_puterror("Wrong free option: ft_append");
	if (str_free == FREE_RIGHT)
		free(right);
	else if (str_free == FREE_LEFT)
		free(left);
	else if (str_free == FREE_BOTH)
	{
		free(right);
		free(left);
	}
	return (result);
}
