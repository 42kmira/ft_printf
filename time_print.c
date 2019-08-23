/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 09:04:05 by kmira             #+#    #+#             */
/*   Updated: 2019/08/22 03:30:56 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

#include "ft_printf.h"
#include "color.h"

#include <stdio.h>

#define STOP 80000

int		main(void)
{
	int i;
	clock_t start;
	clock_t end;
	double cpu_time_a;
	double cpu_time_b;
	double cpu_time_c;

	i = 0;
	start = clock();
	while (i < STOP)
	{
		printf("[SYST]: This test numbs: %200d and this one %s and for %f\n", i, "Super Star", 2.0);
		i++;
	}
	end = clock();
	cpu_time_a = ((double)(end - start)) / CLOCKS_PER_SEC;

	i = 0;
	start = clock();
	while (i < STOP)
	{
		ft_printf("[MINE]: This test numbs: %200d and this one %s and for %f\n", i, "Super Star", 2.0);
		i++;
	}
	end = clock();
	cpu_time_b = ((double)(end - start)) / CLOCKS_PER_SEC;

	i = 0;
	start = clock();
	while (i < STOP)
	{
		write(1, "4", 1);
		write(1, "2", 1);
		write(1, "\n", 1);

		// write(1, "42\n", 3);
		i++;
	}
	end = clock();
	cpu_time_c = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("TIME USED: SYST: %f and MINE: %f, vs BASE: %f", cpu_time_a, cpu_time_b, cpu_time_c);
	return (1);
}
