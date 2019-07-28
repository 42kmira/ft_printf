/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:40:12 by kmira             #+#    #+#             */
/*   Updated: 2019/07/28 06:01:44 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*append(char *a, char *b)
{
	char	*result;
	size_t	length_a;
	size_t	length_b;
	size_t	i;

	length_a = ft_strlen(a);
	length_b = ft_strlen(b);
	result = malloc(sizeof(*result) * (length_a + length_b + 1));
	i = 0;
	// printf("STRING_B 1: %s\n", b);
	while (i < length_a)
	{
		result[i] = a[i];
		i++;
	}
	// printf("STRING_B: %s\n", b);
	while (i - length_a < length_b)
	{
		result[i] = b[i - length_a];
		i++;
	}
	// printf("CHAR %c and CHAR %c\n", result[i - 1], b[i - length_a - 1]);
	result[i] = '\0';
	// printf("STRING: %s\n", result);
	return (result);
}

void	upper_case_string(char *string)
{
	size_t	i;

	i = 0;
	while (string[i] != '\0')
	{
		string[i] = ft_toupper(string[i]);
		i++;
	}
}
