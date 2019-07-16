/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 22:17:51 by kmira             #+#    #+#             */
/*   Updated: 2019/07/15 22:35:59 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *string)
{
	size_t	i;
	size_t	j;
	char	holder;

	i = 0;
	j = ft_strlen(string);
	if (j != 0)
		j--;
	while (i < j)
	{
		holder = string[i];
		string[i] = string[j];
		string[j] = holder;
		i++;
		j--;
	}
	return (string);
}
