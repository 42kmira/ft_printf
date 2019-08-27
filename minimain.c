/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:25:33 by kmira             #+#    #+#             */
/*   Updated: 2019/08/25 23:21:46 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "color.h"
#include "float.h"
#include <stdio.h>

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
	// ft_printf(BOLDWHITE"!!!!!!!!!"BOLDCYAN"NEW TEST FRAME STARTINGS"BOLDWHITE"!!!!!!!!!\n"COLOR_RESET"\n\n");
	// VERIFY("TEST: %c", '\0');
	// VERIFY("ONE TWO %s", "String");
	// VERIFY("Testing %% Three two one %%");
	// VERIFY("")

	// VERIFY("%u", 1);
	// VERIFY("%u", -1);

	// VERIFY("%lu", -533264L);

	// VERIFY("%x", 14);

	// VERIFY("%p", "Test");
	// VERIFY("This string is %p", (void *)1);
	// VERIFY("Length test %hhd and another %d and for giggles %s", (char)5, 0, "'n squiggles");
	// VERIFY("STRING %s\n", "\0");
	// VERIFY("CHAR %c\n", '\0');



	// VERIFY("%#o\n", 42);
	// VERIFY("%#O\n", 42);
	// VERIFY("%#x\n", 42);
	// VERIFY("%#X\n", 42);

	// VERIFY("%#o\n", -1);
	// VERIFY("%#O\n", -1);
	// VERIFY("%#x\n", -1);
	// VERIFY("%#X\n", -1);

	// ft_printf("TEST: % 5.33b\n", UINTMAX_MAX);
	// ft_printf("\n");
	// VERIFY("TEST: % 5.32d\n", 4);

	VERIFY("%q");

	// VERIFY("INT %#0o", 4200);
	// VERIFY("INT %#1o", 4200);
	// VERIFY("INT %#2o", 4200);
	// VERIFY("INT %#5o", 4200);
	// VERIFY("INT %#7o", 4200);
	// VERIFY("INT %#9o", 4200);

	// printf(BLUE"CHANGE TEST"COLOR_RESET"\n");
	// VERIFY("INT %#00o", 4200);
	// VERIFY("INT %#01o", 4200);
	// VERIFY("INT %#02o", 4200);
	// VERIFY("INT %#05o", 4200);
	// VERIFY("INT %#07o", 4200);
	// VERIFY("INT %#09o", 4200);

	// printf(BLUE"CHANGE TEST"COLOR_RESET"\n");
	// VERIFY("INT %#00.5o", 4200);
	// VERIFY("INT %#01.5o", 4200);
	// VERIFY("INT %#02.5o", 4200);
	// VERIFY("INT %#05.5o", 4200);
	// VERIFY("INT %#07.5o", 4200);
	// VERIFY("INT %#09.5o", 4200);

	// printf(BLUE"CHANGE TEST"COLOR_RESET"\n");
	// VERIFY("INT %#0.5o", 4200);
	// VERIFY("INT %#1.5o", 4200);
	// VERIFY("INT %#2.5o", 4200);
	// VERIFY("INT %#5.5o", 4200);
	// VERIFY("INT %#7.5o", 4200);
	// VERIFY("INT %#9.5o", 4200);

	// printf(BLUE"CHANGE TEST"COLOR_RESET"\n");
	// VERIFY("INT %#0.5o", 4200);
	// VERIFY("INT %#1.5o", 4200);
	// VERIFY("INT %#2.5o", 4200);
	// VERIFY("INT %#5.5o", 4200);
	// VERIFY("INT %#7.5o", 4200);
	// VERIFY("INT %#9.5o", 4200);

	// VERIFY("INT %#0+o", 4200);
	// VERIFY("INT %#0+1o", 4200);
	// VERIFY("INT %#0+2o", 4200);
	// VERIFY("INT %#0+4o", 4200);
	// VERIFY("INT %#0+5o", 4200);
	// VERIFY("INT %#0+10o", -4200);

	// VERIFY("INT %.1o", 42);
	// VERIFY("INT %.2o", 42);
	// VERIFY("INT %.3o", 42);
	// VERIFY("INT % -.8o", 42);

	// VERIFY(BLUE"INT % 03o"COLOR_RESET, 0);

	// VERIFY("INT %-.1o", -42);
	// VERIFY("INT %-.2o", -42);
	// VERIFY("INT % -5.3o", -42);

	// VERIFY("INT %+5.3o", -42);

	// printf(BLUE"NEW TEST\n\n"COLOR_RESET);

	// VERIFY("INT %+.1o", 42);
	// VERIFY("INT %+.2o", 42);
	// VERIFY("INT %+.3o", 42);
	// VERIFY("INT %+-.8o", 42);

	// VERIFY(BLUE"INT %+03o"COLOR_RESET, 0);

	// VERIFY("INT %+-.1o", -42);
	// VERIFY("INT %+-.2o", -42);
	// VERIFY("INT %+-5.3o", -42);

	// VERIFY("INT % 5o", 42);

	// VERIFY("INT %o", 0);

	// VERIFY("INT %o", 0);

	// VERIFY("INT %-.10hho", (char)128);

	// VERIFY("%#o", 0);

	// VERIFY("%Lf", (long double)-2.01);
	// VERIFY("%Lf", (long double)-1);
	// printf("SIZE: %zu\n", sizeof(double));

	// VERIFY("%f", (double)1);
	// VERIFY("%f", (double)2);

	// VERIFY("%f", (double)5);


	// VERIFY("%.80f", (double).061434961347513554563453465341653416);
	// VERIFY("%f", (double)8);
	// VERIFY("%f", (double)16);
	// VERIFY("%f", (double)64);
	// VERIFY("%f", (double)128);

	// VERIFY("%f", (double)32);

	// VERIFY("%f", (double)1.5);

	// VERIFY("%f", (double)34.25);

	// VERIFY("%.200Lf", (long double).0000000000000000000000003674613784167464653168451346853165341653416531654165316534165321653120196854310324615794651357461384132416531);

	// VERIFY("%f", (double)1238.23);

	// VERIFY("%.200f", (double).00000862154564984156784531984615646531985129684684653496510001);

	// VERIFY("%.40f", (double).0011316138413546);


	// VERIFY("%Lf", (long double)-1);
	// VERIFY("%Lf", (long double)-10);
	// VERIFY("%Lf", (long double)-.1);
	// VERIFY("%Lf", (long double)-.00001);
	// VERIFY("%Lf", (long double)-2341);
	// VERIFY("%Lf", (long double)-14312341);
	// VERIFY("%Lf", (long double)-341351);
	// VERIFY("%Lf", (long double)-135235.41234123);

	// VERIFY("%.0Lf", (long double)-1);

	// VERIFY("%#05x", 43);

	// VERIFY("%-7s\n", "Test");
	// VERIFY("%7s\n", "Test");

	// VERIFY("%.0f", 1.0);
	// VERIFY("%05.0f", 7.3);
	// VERIFY("%05.1f", 7.3);
	// VERIFY("%05.0f", -7.3);
	// VERIFY("%05.1f", -7.3);
	// VERIFY("%-5.0f", 7.3);
	// VERIFY("%-5.1f", 7.3);

	// VERIFY("%f", 764679856466138745168413468516846466413.33131);
	// printf("%f", 764679856466138745168413468516846466413.33131);

	// VERIFY("% 05.0f", 7.3);

	// VERIFY("%.500Lf", (long double).000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000009482134);

	// VERIFY("%Lf", LDBL_MIN);

	// VERIFY("%.1535f", -DBL_MIN);
	// VERIFY("%.2000f", -DBL_MIN);

	// VERIFY("%09s", "TEST");

	// printf("%.100000000Lf", LDBL_MIN);
}
