/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:25:33 by kmira             #+#    #+#             */
/*   Updated: 2019/07/11 18:11:27 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "color.h"

int mine_result;
int syst_result;

#define VERIFY(msg, ...) mine_result = ft_printf("[MINE]: "msg"\n", ## __VA_ARGS__); \
						 syst_result =    printf("[SYST]: "msg"\n", ## __VA_ARGS__); \
						 if (mine_result == syst_result)							 \
						 	printf(BOLDGREEN"[RESULT]: [MINE]: %d [SYST]: %d\n"COLOR_RESET"\n", mine_result, syst_result); \
						 else														 \
						 	printf(RED"[RESULT]: [MINE]: %d [SYST]: %d\n"COLOR_RESET"\n", mine_result, syst_result);


int	main(void)
{
	VERIFY("ONE TWO %s", "String");

	VERIFY("Testing %% Three two one %%");

	VERIFY("Testing %---s", "STRING");
	// VERIFY("Another one");
}
