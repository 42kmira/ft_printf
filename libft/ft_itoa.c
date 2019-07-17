/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:58:18 by kmira             #+#    #+#             */
/*   Updated: 2019/07/17 12:04:22 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*result;
	char	*head;
	int		digits;

	digits = ft_digit_amount(n);
	if (!(result = malloc(sizeof(*result) * (digits + 1))))
		return (NULL);
	head = result;
	if (n >= 0)
		n = n * -1;
	else
	{
		*result++ = '-';
		digits--;
	}
	*(result + digits) = '\0';
	while (digits > 0)
	{
		*(result + digits - 1) = ((n % 10) * -1) + '0';
		n = n / 10;
		digits--;
	}
	return (head);
}

// char		*itoa_base(long long int num, int base, int flag)
// {
// 	char			alloc[50];
// 	char			*res;
// 	int				i;
// 	int				neg;

// 	neg = 1;
// 	res = (flag == 0) ? "0123456789abcdef" : "0123456789ABCDEF";
// 	if (num == 0)
// 		return (ft_strdup("0"));
// 	i = 48;
// 	alloc[49] = '\0';
// 	if (num < 0)
// 		neg = -1;
// 	while (num != 0)
// 	{
// 		alloc[i--] = res[neg * (num % base)];
// 		num /= base;
// 	}
// 	return (ft_strdup(&(alloc[++i])));
// }
