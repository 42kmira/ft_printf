/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:25:33 by kmira             #+#    #+#             */
/*   Updated: 2019/07/17 21:13:13 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "color.h"

int mine_result;
int syst_result;

#define VERIFY(msg, ...) mine_result = ft_printf("[MINE]: |"msg"|\n", ## __VA_ARGS__); \
						 syst_result =    printf("[SYST]: |"msg"|\n", ## __VA_ARGS__); \
						 if (mine_result == syst_result)							 \
						 	printf(BOLDGREEN"[RESULT]: [MINE]: %d [SYST]: %d\n"COLOR_RESET"\n", mine_result, syst_result); \
						 else														 \
						 	printf(RED"[RESULT]: [MINE]: %d [SYST]: %d\n"COLOR_RESET"\n", mine_result, syst_result);


int	main(void)
{
	ft_printf(BOLDWHITE"!!!!!!!!!"BOLDCYAN"NEW TEST FRAME STARTINGS"BOLDWHITE"!!!!!!!!!\n"COLOR_RESET);
	VERIFY("TEST: %c", '\0');
	VERIFY("ONE TWO %s", "String");
	VERIFY("Testing %% Three two one %%");

	VERIFY("%u", 1);
	VERIFY("%u", -1);

	VERIFY("%lu", -533264L);

	VERIFY("%x", 14);

	VERIFY("%p", "Test");

	VERIFY("%#o\n", 42);
	VERIFY("%#O\n", 42);
	VERIFY("%#x\n", 42);
	VERIFY("%#X\n", 42);

	VERIFY("%#o\n", -1);
	VERIFY("%#O\n", -1);
	VERIFY("%#x\n", -1);
	VERIFY("%#X\n", -1);

	VERIFY("")
	VERIFY("This string is %p\n", (void *)1);

	VERIFY("Length test %hhd and another %d and for giggles %s", (char)5, 0, "'n squiggles");
	VERIFY("STRING %s\n", "\0");
	VERIFY("CHAR %c\n", '\0');

	VERIFY("INT %0d", 4200);
	VERIFY("INT %1d", 4200);
	VERIFY("INT %2d", 4200);
	VERIFY("INT %5d", 4200);
	VERIFY("INT %7d", 4200);
	VERIFY("INT %9d", 4200);

	printf(BLUE"CHANGE TEST"COLOR_RESET"\n");
	VERIFY("INT %00d", 4200);
	VERIFY("INT %01d", 4200);
	VERIFY("INT %02d", 4200);
	VERIFY("INT %05d", 4200);
	VERIFY("INT %07d", 4200);
	VERIFY("INT %09d", 4200);

	printf(BLUE"CHANGE TEST"COLOR_RESET"\n");
	VERIFY("INT %00.5d", 4200);
	VERIFY("INT %01.5d", 4200);
	VERIFY("INT %02.5d", 4200);
	VERIFY("INT %05.5d", 4200);
	VERIFY("INT %07.5d", 4200);
	VERIFY("INT %09.5d", 4200);

	printf(BLUE"CHANGE TEST"COLOR_RESET"\n");
	VERIFY("INT %0.5d", 4200);
	VERIFY("INT %1.5d", 4200);
	VERIFY("INT %2.5d", 4200);
	VERIFY("INT %5.5d", 4200);
	VERIFY("INT %7.5d", 4200);
	VERIFY("INT %9.5d", 4200);

	printf(BLUE"CHANGE TEST"COLOR_RESET"\n");
	VERIFY("INT % 0.5d", 4200);
	VERIFY("INT % 1.5d", 4200);
	VERIFY("INT % 2.5d", 4200);
	VERIFY("INT % 5.5d", 4200);
	VERIFY("INT % 7.5d", 4200);
	VERIFY("INT % 9.5d", 4200);

	VERIFY("INT %+-.5d", 4200);
	VERIFY("INT %+-1.5d", 4200);
	VERIFY("INT %+-2.5d", 4200);
	VERIFY("INT %+-5.5d", 4200);
	VERIFY("INT %+-7.5d", 4200);
	VERIFY("INT %+-9.5d", 4200);
}
