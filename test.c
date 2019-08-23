/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 03:50:21 by kmira             #+#    #+#             */
/*   Updated: 2019/08/21 20:13:20 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

#define TEST(num) 	t_test_ ## num	test_ ## num; \
					printf("sizeof t_test_"#num" num: %lu\n", sizeof(test_ ## num));

typedef struct	s_test_01
{
	char l : 1;
}		t_test_01;

typedef struct	s_test_02
{
	char l : 4;
}		t_test_02;

typedef struct	s_test_03
{
	char l : 7;
}		t_test_03;

typedef struct	s_test_04
{
	char l : 8;
}		t_test_04;

/*
** anything above the bit length of the variable will give a compiler
** error
** typedef struct	s_test_04
** {
** 	char l : 9;
** }		t_test_04;
*/

typedef struct	s_test_05
{
	char l : 4;
	char b : 3;
}		t_test_05;

typedef struct	s_test_06
{
	char l : 4;
	char b : 4;
}		t_test_06;

typedef struct	s_test_07
{
	char l : 4;
	char b : 5;
}		t_test_07;

typedef struct s_test_08
{
	short	d : 10;
	char	l : 4;
}		t_test_08;

typedef struct s_test_09
{
	short	d : 15;
	char	l : 4;
}		t_test_09;

typedef struct s_test_10
{
	char	a;
	char	l;
	char	m;
	char	p;
	int		q: 1;
}		t_test_10;

int	main(void)
{
	TEST(01);
	TEST(02);
	TEST(03);
	TEST(04);
	TEST(05);
	TEST(06);
	TEST(07);
	TEST(08);
	TEST(09);
	TEST(10);
	return (0);
}
