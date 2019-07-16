/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:25:33 by kmira             #+#    #+#             */
/*   Updated: 2019/07/16 14:18:37 by kmira            ###   ########.fr       */
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
	// ft_printf("TEST: %c\n", '\0');
	// VERIFY("TEST: %c", '\0');
	// VERIFY("ONE TWO %s", "String");
	// VERIFY("Testing %% Three two one %%");

	VERIFY("%u", 1);
	VERIFY("%u", -1);

	VERIFY("%lu", -533264L);

	VERIFY("%x", 14);
	// VERIFY("")
	// VERIFY("This string is %p\n", (void *)1);


	// VERIFY("Length test %hhd and another %d and for giggles %s", (char)5, 0, "' squiggles");
	// VERIFY("STRING %s\n", "\0");
	// VERIFY("CHAR %c\n", '\0');
}
