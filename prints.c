/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 21:03:23 by kmira             #+#    #+#             */
/*   Updated: 2019/08/22 02:22:13 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/color.h"

void	width_1_flag_none(void){
	printf(BOLDGREEN"WIDTH: 1 FLAGS: NONE"COLOR_RESET"\n");
	printf("%1c\n", '*');
	printf("%1s\n", "42");
	printf("%1p\n", (void *)42);
	printf("%1d\n", 42);
	printf("%1i\n", 42);
	printf("%1o\n", 42);
	printf("%1u\n", 42);
	printf("%1x\n", 42);
	printf("%1X\n", 42);
	printf("%1f\n", (float)42);
	printf("%1%\n");
}
void	width_1_flag_minus(void){
	printf(BOLDGREEN"WIDTH: 1 FLAGS: -"COLOR_RESET"\n");
	printf("%-1c\n", '*');
	printf("%-1s\n", "42");
	printf("%-1p\n", (void *)42);
	printf("%-1d\n", 42);
	printf("%-1i\n", 42);
	printf("%-1o\n", 42);
	printf("%-1u\n", 42);
	printf("%-1x\n", 42);
	printf("%-1X\n", 42);
	printf("%-1f\n", (float)42);
	printf("%-1%\n");
}
void	width_12_flag_none(void){
	printf(BOLDGREEN"WIDTH: 12 FLAGS: NONE"COLOR_RESET"\n");
	printf("%12c\n", '*');
	printf("%12s\n", "42");
	printf("%12p\n", (void *)42);
	printf("%12d\n", 42);
	printf("%12i\n", 42);
	printf("%12o\n", 42);
	printf("%12u\n", 42);
	printf("%12x\n", 42);
	printf("%12X\n", 42);
	printf("%12f\n", (float)42);
	printf("%12%\n");
}
void	width_12_flag_minus(void){
	printf(BOLDGREEN"WIDTH: 12 FLAGS: -"COLOR_RESET"\n");
	printf("%-12c\n", '*');
	printf("%-12s\n", "42");
	printf("%-12p\n", (void *)42);
	printf("%-12d\n", 42);
	printf("%-12i\n", 42);
	printf("%-12o\n", 42);
	printf("%-12u\n", 42);
	printf("%-12x\n", 42);
	printf("%-12X\n", 42);
	printf("%-12f\n", (float)42);
	printf("%-12%\n");
}
void	width_1_flag_plus(void){
	printf(BOLDGREEN"WIDTH: 1 FLAGS: +"COLOR_RESET"\n");
	// printf("%+1c\n", '*');
	// printf("%+1s\n", "42");
	// printf("%+1p\n", (void *)42);
	printf("%+1d\n", 42);
	printf("%+1i\n", 42);
	// printf("%+1o\n", 42);
	// printf("%+1u\n", 42);
	// printf("%+1x\n", 42);
	// printf("%+1X\n", 42);
	printf("%+1f\n", (float)42);
	printf("%+1%\n");
}
void	width_12_flag_plus(void){
	printf(BOLDGREEN"WIDTH: 12 FLAGS: +"COLOR_RESET"\n");
	// printf("%+12c\n", '*');
	// printf("%+12s\n", "42");
	// printf("%+12p\n", (void *)42);
	printf("%+12d\n", 42);
	printf("%+12i\n", 42);
	// printf("%+12o\n", 42);
	// printf("%+12u\n", 42);
	// printf("%+12x\n", 42);
	// printf("%+12X\n", 42);
	printf("%+12f\n", (float)42);
	printf("%+12%\n");
}
void	width_1_flag_zero(void){
	printf(BOLDGREEN"WIDTH: 1 FLAGS: 0"COLOR_RESET"\n");
	// printf("%01c\n", '*');
	// printf("%01s\n", "42");
	// printf("%01p\n", (void *)42);
	printf("%01d\n", 42);
	printf("%01i\n", 42);
	printf("%01o\n", 42);
	printf("%01u\n", 42);
	printf("%01x\n", 42);
	printf("%01X\n", 42);
	printf("%01f\n", (float)42);
	printf("%01%\n");
}
void	width_12_flag_zero(void){
	printf(BOLDGREEN"WIDTH: 12 FLAGS: 0"COLOR_RESET"\n");
	// printf("%012c\n", '*');
	// printf("%012s\n", "42");
	// printf("%012p\n", (void *)42);
	printf("%012d\n", 42);
	printf("%012i\n", 42);
	printf("%012o\n", 42);
	printf("%012u\n", 42);
	printf("%012x\n", 42);
	printf("%012X\n", 42);
	printf("%012f\n", (float)42);
	printf("%012%\n");
}
void	string_precision(void)
{
	printf(BOLDGREEN"STRINGS PRESICION"COLOR_RESET"\n");
	printf("%.0s\n", NULL);
	printf("%.0s\n", "\0");
	printf("%.0s\n", "TEST");

	printf("%.1s\n", NULL);
	printf("%.1s\n", "\0");
	printf("%.1s\n", "TEST");

	printf("%.10s\n", "Test\0Hidden");
	printf("%.5s\n", "Test\0Hidden");
}
void	string_precision_and_width(void){
	printf(BOLDGREEN"STRINGS PRESICION and WIDTH"COLOR_RESET"\n");
	printf("%1.0s\n", NULL);
	printf("%1.0s\n", "\0");
	printf("%1.0s\n", "TEST");

	printf("%1.1s\n", NULL);
	printf("%1.1s\n", "\0");
	printf("%1.1s\n", "TEST");

	printf("%1.10s\n", "Test\0Hidden");
	printf("%1.5s\n", "Test\0Hidden");

	printf("%10.0s\n", NULL);
	printf("%10.0s\n", "\0");
	printf("%10.0s\n", "TEST");

	printf("%10.1s\n", NULL);
	printf("%10.1s\n", "\0");
	printf("%10.1s\n", "TEST");

	printf("%10.10s\n", "Test\0Hidden");
	printf("%10.5s\n", "Test\0Hidden");
	printf("%10.5s\n", "Test when longer");
}
void	char_width(void)
{
	printf(BOLDGREEN"CHAR WIDTH"COLOR_RESET"\n");
	printf("%1c\n", '*');

}

//Need to run test where I check for max width and how it handles certain cases for return and so on

void	integer_test(void)
{
	printf(BOLDGREEN"INTEGER TEST"COLOR_RESET"\n");
	printf("%d\n", 42);
	printf("%-d\n", 42);
	printf("%+d\n", 42);
	printf("% d\n", 42);
	printf("%0d\n", 42);

	printf("%12d\n", 42);
	printf("%-12d\n", 42);
	printf("%+12d\n", 42);
	printf("% 12d\n", 42);
	printf("%012d\n", 42);

	printf(BOLDGREEN"\nINTEGER TEST PRECISION"COLOR_RESET"\n");

	printf("%.2d\n", 42);
	printf("%-.2d\n", 42);
	printf("%+.2d\n", 42);
	printf("% .2d\n", 42);
	printf("%0.2d\n", 42);
	printf("\n");
	printf("%.1d\n", 42);
	printf("%-.1d\n", 42);
	printf("%+.1d\n", 42);
	printf("% .1d\n", 42);
	printf("%0.1d\n", 42);
	printf("\n");
	printf("%.12d\n", 42);
	printf("%-.12d\n", 42);
	printf("%+.12d\n", 42);
	printf("% .12d\n", 42);
	printf("%0.12d\n", 42);
	printf("\n");
	printf("%.2d\n", 4200);
	printf("%-.2d\n", 4200);
	printf("%+.2d\n", 4200);
	printf("% .2d\n", 4200);
	printf("%0.2d\n", 4200);

	printf(BOLDGREEN"\nINTEGER TEST PRECISION AND WIDTH"COLOR_RESET"\n");
	printf("%7.12d\n", 42);
	printf("%-7.12d\n", 42);
	printf("%+7.12d\n", 42);
	printf("% 7.12d\n", 42);
	printf("%07.12d\n", 42);
	printf("\n");
	printf("%7.4d\n", 42);
	printf("%-7.4d\n", 42);
	printf("%+7.4d\n", 42);
	printf("% 7.4d\n", 42);
	printf("%07.4d\n", 42);
	printf("\n");
	printf("%7.4d\n", 420042);
	printf("%-7.4d\n", 420042);
	printf("%+7.4d\n", 420042);
	printf("% 7.4d\n", 420042);
	printf("%07.4d\n", 420042);
	printf("\n");
	printf("%4.7d\n", 420042);
	printf("%-4.7d\n", 420042);
	printf("%+4.7d\n", 420042);
	printf("% 4.7d\n", 420042);
	printf("%04.7d\n", 420042);
	printf("\n");
	printf("%4.3d\n", 420042);
	printf("%-4.3d\n", 420042);
	printf("%+4.3d\n", 420042);
	printf("% 4.3d\n", 420042);
	printf("%04.3d\n", 420042);
}
void	interger_test_zero(void)
{
	printf(BOLDGREEN"\nINTEGER TEST ZERO"COLOR_RESET"\n");
	printf("%.0d\n", 0);
	printf("%-.0d\n", 0);
	printf("%+.0d\n", 0);
	printf("% .0d\n", 0);
	printf("%0.0d\n", 0);
	printf("\n");
	printf("%4.0d\n", 0);
	printf("%-4.0d\n", 0);
	printf("%+4.0d\n", 0);
	printf("% 4.0d\n", 0);
	printf("%04.0d\n", 0);
}

void	hex_test(void)
{
	printf(BOLDGREEN"\nHEX TEST"COLOR_RESET"\n");
	printf("%x\n", 42);

	printf("%.5x\n", 42);
	printf("%.3x\n", 42);
	printf("%.2x\n", 42);
	printf("%.1x\n", 42);
	printf("%.0x\n", 42);

	printf(BOLDGREEN"\nHEX TEST WIDTH and PREC"COLOR_RESET"\n");
	printf("%5x\n", 42);
	printf("%3x\n", 42);
	printf("%2x\n", 42);
	printf("%1x\n", 42);
	printf("\n");
	printf("%5.5x\n", 42);
	printf("%5.3x\n", 42);
	printf("%5.2x\n", 42);
	printf("%5.1x\n", 42);
	printf("%5.0x\n", 42);
	printf("\n");
	printf("%5.5x\n", 42);
	printf("%3.5x\n", 42);
	printf("%2.5x\n", 42);
	printf("%1.5x\n", 42);
	printf("\n");
	printf("%#.5x\n", 42);
	printf("%#.3x\n", 42);
	printf("%#.2x\n", 42);
	printf("%#.1x\n", 42);
	printf("%#.0x\n", 42);

	printf(BOLDGREEN"\nHEX TEST WIDTH and PREC with HASH"COLOR_RESET"\n");
	printf("%#5x\n", 42);
	printf("%#3x\n", 42);
	printf("%#2x\n", 42);
	printf("%#1x\n", 42);
	printf("\n");
	printf("%#5.5x\n", 42);
	printf("%#5.3x\n", 42);
	printf("%#5.2x\n", 42);
	printf("%#5.1x\n", 42);
	printf("%#5.0x\n", 42);
	printf("\n");
	printf("%#5.5x\n", 42);
	printf("%#3.5x\n", 42);
	printf("%#2.5x\n", 42);
	printf("%#1.5x\n", 42);
	printf("\n");
	printf("%#.5x\n", 42);
	printf("%#.3x\n", 42);
	printf("%#.2x\n", 42);
	printf("%#.1x\n", 42);
	printf("%#.0x\n", 42);
}

#include <stdlib.h>

int		main(void)
{
	printf(BOLDBLUE"[[[[-__.-._-START-_.-.__-]]]]"COLOR_RESET"\n");

	width_12_flag_zero();
	string_precision();
	string_precision_and_width();
	char_width();
	integer_test();
	interger_test_zero();

	// printf("%p\n", (void *)-1);

	// printf("TEST%12d\n", 10001000);

	// printf("%#o\n", 42);
	// printf("%#O\n", 42);
	// printf("%#x\n", 42);
	// printf("%#X\n", 42);

	// printf("%#o\n", -1);
	// printf("%#O\n", -1);
	// printf("%#x\n", -1);
	// printf("%#X\n", -1);

	// hex_test();

	// printf("%013.2d\n", 7);
	// printf("%013.2d\n", -7);

	return (0);
}
