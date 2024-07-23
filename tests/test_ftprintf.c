/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ftprintf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:46:15 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/23 16:40:30 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../ft_printf_bonus.h"

// colors
#define RED "\033[1;31m"
#define GRN "\033[1;32m"
#define YLO "\033[1;33m"
#define RST "\033[0m"

static int FAIL = 0;

void eval_fail()
{
	if (FAIL) {
		printf(RED "\n---> there were errors...\n" RST);
		exit(1);
	}
	else {
		printf(GRN "\n---> everythink ok :)\n" RST);
		exit(0);
	}
}

// implemented elsewhere... 
void test_ftpr_smpl();

void test_iscomplconv(void)
{
	printf(YLO "\n---- test_iscomplconv ----\n\n" RST);
	int i = 0;
	int c = 0;
	char *s;

	// #1
	printf(YLO "-- iscomplconv_test #1 --\n" RST);
	s = "%4d";
	printf(YLO "-- testing \"%s\"%s\n", s,RST);
	i = ftpr_compl_isconv(s);
	c = 1;
	if (i != c) {
		printf(RED "#1 Error!\n" RST);
		printf(RED "i = %d\nshould be: %d\n" RST, i, c);
		FAIL = 1;
	}
	else
		printf(GRN "alrighty!\n" RST);
	printf(YLO "--\n\n" RST);
	// #2
	printf(YLO "-- iscomplconv_test #2 --\n" RST);
	s = "%.4.d";
	printf(YLO "-- testing \"%s\"%s\n", s,RST);
	i = ftpr_compl_isconv(s);
	c = 0;
	if (i != c) {
		printf(RED "#2 Error!\n" RST);
		printf(RED "i = %d\nshould be: %d\n" RST, i, c);
		FAIL = 1;
	}
	else
		printf(GRN "alrighty!\n" RST);
	printf(YLO "--\n\n" RST);
	// #3
	printf(YLO "-- iscomplconv_test #3 --\n" RST);
	s = "%+-0---+##020.1204812%";
	printf(YLO "-- testing \"%s\"%s\n", s,RST);
	i = ftpr_compl_isconv(s);
	c = 1;
	if (i != c) {
		printf(RED "#3 Error!\n" RST);
		printf(RED "i = %d\nshould be: %d\n" RST, i, c);
		FAIL = 1;
	}
	else
		printf(GRN "alrighty!\n" RST);
	printf(YLO "--\n\n" RST);
	// #4
	printf(YLO "-- iscomplconv_test #4 --\n" RST);
	s = "%";
	printf(YLO "-- testing \"%s\"%s\n", s,RST);
	i = ftpr_compl_isconv(s);
	c = -1;
	if (i != c) {
		printf(RED "#4 Error!\n" RST);
		printf(RED "i = %d\nshould be: %d\n" RST, i, c);
		FAIL = 1;
	}
	else
		printf(GRN "alrighty!\n" RST);
	printf(YLO "--\n\n" RST);
	// #5
	printf(YLO "-- iscomplconv_test #5 --\n" RST);
	s = "%-0+-000-20.345";
	printf(YLO "-- testing \"%s\"%s\n", s,RST);
	i = ftpr_compl_isconv(s);
	c = -1;
	if (i != c) {
		printf(RED "#5 Error!\n" RST);
		printf(RED "i = %d\nshould be: %d\n" RST, i, c);
		FAIL = 1;
	}
	else
		printf(GRN "alrighty!\n" RST);
	printf(YLO "--\n\n" RST);
	// #6
	printf(YLO "-- iscomplconv_test #6 --\n" RST);
	s = "%053-324d";
	printf(YLO "-- testing \"%s\"%s\n", s,RST);
	i = ftpr_compl_isconv(s);
	c = 0;
	if (i != c) {
		printf(RED "#6 Error!\n" RST);
		printf(RED "i = %d\nshould be: %d\n" RST, i, c);
		FAIL = 1;
	}
	else
		printf(GRN "alrighty!\n" RST);
	printf(YLO "--\n\n" RST);
	// #7
	printf(YLO "-- iscomplconv_test #7 --\n" RST);
	s = "%2147483647d";
	printf(YLO "-- testing \"%s\"%s\n", s,RST);
	i = ftpr_compl_isconv(s);
	c = 1;
	if (i != c) {
		printf(RED "#7 Error!\n" RST);
		printf(RED "i = %d\nshould be: %d\n" RST, i, c);
		FAIL = 1;
	}
	else
		printf(GRN "alrighty!\n" RST);
	printf(YLO "--\n\n" RST);
	// #8
	printf(YLO "-- iscomplconv_test #8 --\n" RST);
	s = "%21474836471d";
	printf(YLO "-- testing \"%s\"%s\n", s,RST);
	i = ftpr_compl_isconv(s);
	c = -1;
	if (i != c) {
		printf(RED "#8 Error!\n" RST);
		printf(RED "i = %d\nshould be: %d\n" RST, i, c);
		FAIL = 1;
	}
	else
		printf(GRN "alrighty!\n" RST);
	printf(YLO "--\n\n" RST);
}

void test_printf(void)
{
	printf(YLO "\n---- test_printf ----\n\n" RST);
	ft_printf("%+-d\n", 5);
	ft_printf("%+-0---+ 23452.234pbla\n", 5);
	ft_printf("%+d\n", 5);
	ft_printf("%+d\n", -5);
	ft_printf("%053-324d\n", 5);
	ft_printf("\n:::: compl_atol ::::\n\n");
	ft_printf("compl_atoi(21474836471) = %d\n", ftpr_atoi_overflow("21474836471"));
	int x = printf("%.2147483648d", 1);
	printf("x = %d\n", x);
}

void test_flags(void)
{
	int x1, x2;

	// x1 = ft_printf("%#3.12X", -1024u);
	x1 = ft_printf("%#20.12X", 0);
	printf("\n");
	// x2 = printf("%#3.12X", -1024u);	
	x2 = printf("%#20.12X", 0);
	printf("\n");
	printf("x1, x2 = %d, %d\n\n", x1, x2);

	x1 = ft_printf("%#3.12X", -1024u);
	printf("\n");
	x2 = printf("%#3.12X", -1024u);	
	printf("\n");
	printf("x1, x2 = %d, %d\n\n", x1, x2);

	x1 = ft_printf("%#.12x", -1024u);
	printf("\n");
	x2 = printf("%#.12x", -1024u);	
	printf("\n");
	printf("x1, x2 = %d, %d\n\n", x1, x2);

	x1 = ft_printf("%#.12x", 0);
	printf("\n");
	x2 = printf("%#.12x", 0);	
	printf("\n");
	printf("x1, x2 = %d, %d\n\n", x1, x2);

	char *str = ftpr_utoa(-1);
	printf("str = %s\n", str);
	x1 = ft_printf("%#x", -1);
	printf("\n");
	x2 = printf("%#x", -1);	
	printf("\n");
	printf("x1, x2 = %d, %d\n\n", x1, x2);

	x1 = ft_printf("%0#38.8X", 159916024);
	printf("\n");
	x2 = printf("%0#38.8X", 159916024);
	printf("\n");
	printf("x1, x2 = %d, %d\n\n", x1, x2);

	x1 = ft_printf("%#48.2X", 159916024);
	printf("\n");
	x2 = printf("%#48.2X", 159916024);
	printf("\n");
	printf("x1, x2 = %d, %d\n\n", x1, x2);

	x1 = ft_printf("42%+55d42", 0);
	printf("\n");
	x2 = printf("42%+55d42", 0);
	printf("\n");
	printf("x1, x2 = %d, %d\n\n", x1, x2);

	x1 = ft_printf("% -2d", -1047739756);
	printf("\n");
	x2 = printf("% -2d", -1047739756);
	printf("\n");
	printf("x1, x2 = %d, %d\n\n", x1, x2);

	x1 = ft_printf("% 10d", 1885268190);
	printf("\n");
	x2 = printf("% 10d", 1885268190);
	printf("\n");
	printf("x1, x2 = %d, %d\n\n", x1, x2);

	x1 = ft_printf("!%32c!", (char)0);
	printf("\n");
	x2 = printf("!%32c!", (char)0);
	printf("\n");
	printf("x1, x2 = %d, %d\n\n", x1, x2);

	x1 = ft_printf("!%-32.12i!", INT_MIN);
	printf("\n");
	x2 = printf("!%-32.12i!", INT_MIN);
	printf("\n");
	printf("x1, x2 = %d, %d\n\n", x1, x2);

	x1 = ft_printf("!%-32c!", 'A');
	printf("\n");
	x2 = printf("!%-32c!", 'A');
	printf("\n");
	printf("x1, x2 = %d, %d\n\n", x1, x2);

	x1 = ft_printf("!%.q!", 'A');
	printf("\n");
	x2 = printf("!%.()=?!", 'A');
	printf("\n");
	printf("x1, x2 = %d, %d\n\n", x1, x2);

	x1 = ft_printf("!%+6u!", 42);
	printf("\n");
	x2 = printf("!%+6u!", 42);
	printf("\n");
	printf("x1, x2 = %d, %d\n\n", x1, x2);

	printf("------------------------------------------\n");
	x1 = ft_printf("!%24.15p!", "at");
	printf("\n");
	x2 = printf("!%24.15p!", "at");
	printf("\n");
	printf("x1, x2 = %d, %d\n\n", x1, x2);

	printf("------------------------------------------\n");
	x1 = ft_printf("42%49.36x42", 0);
	printf("\n");
	x2 = printf("42%49.36x42", 0);
	printf("\n");
	printf("x1, x2 = %d, %d\n\n", x1, x2);

}

int main(void)
{
	test_ftpr_smpl();
	test_iscomplconv();
	test_printf();
	test_flags();
	eval_fail();
}
