/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_charcuterie.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:59:55 by amacieje          #+#    #+#             */
/*   Updated: 2017/04/21 18:34:35 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include <inttypes.h>
#include "libftprintf.h"

char			*ft_uitoa_base(unsigned long long int decimal, int base);

int		main()
{
//	int	li;

/*	li = 214748364780;
	printf("%d\n", li);
	li = -20;
	li = (long int)li;
	printf("%d\n", li);
	printf("%ld\n", li);
	printf("%lld\n", li);
	printf("%jd\n", li);
	printf("%zd\n", li);
//	printf("%-25s", "Hello\n");
//	printf("%1$.*2$o", 4000, 5);
	printf("%4.3f\n", 3.1456);
	fflush(stdout);
	write(1, "X", 1);
	printf("%ld\n", i);
	printf("%.0d", 0);
	size_t		j;

	j = 54;
	j = printf("%hhd", 129);

	long double	d = 3.1415926535;
	char	*a = "ab";*/

//	printf("%.12Lg\n", d);
//	printf("%U\n", 2147483646845);
//	printf("%ld\n", -2147836468);
//	printf("%d\n", -214783646);
//	printf("%U\n", 2147);
//	printf("%p\n", a);
/*	printf("%d bytes", sizeof(wchar_t));
	write(1, '0XE2', 4);
	write(1, '0X82', 4);
	write(1, '0XAC', 4);*/
/*	printf("%dbye\n", 25);
//	printf("%+-++0*d\n", 5, +4);
//	printf("%010s", "Snek");
	printf("%.0d\n", 25);
	printf("%5d\n", 25);*/
//	printf("%+5.0d\n", 0);

/*	printf("%D\n", -1);
	printf("%ld\n", li);
	printf("%zd\n", li);*/
//	printf("%o\n", -25);
	/*int		a;
	void	*p;
	unsigned int	d;

	p = &a;
	d = (unsigned long long int)p;
	printf("%20p\n", p);
	printf("%x\n", d);
	int	a = -42;
	unsigned int b = (unsigned int)a;
	char	*o;

	o = ft_uitoa_base(b, 16);
	printf("%u\n", b);
	printf("%s\n", o);*/
	//unsigned int	i = L'€';
//	unsigned int	binary;
//	unsigned int	c = L'€';

//	setlocale(LC_CTYPE, "");
//	binary = (c & 0b00111111) | 0b10000000;
//	printf("%d\n", printf("%lc\n", L'𝄞'));
//	printf("%d\n", printf("%lc\n", L'요'));
//	printf("%d\n", printf("%lc\n", 0b1010110010110011));
//	printf("%d\n", printf("%C\n", 5));
//	printf("%s\n", ft_uitoa_base(binary, 16));
//	printf("%d\n", ft_printf("%lc\n", L'요'));
//	printf("%d\n", ft_printf("%lc\n", 0b1010110010110011));
//	printf("%d\n", ft_printf("%s\n", "☆è"));
//	printf("%d\n", printf("%S\n", L"☆è"));
//	printf("%d\n", ft_printf("%S\n", L"longè"));
	printf("%d\n", ft_printf("%S\n", L"iiĀop"));
//	printf("%d\n", printf("%S\n", L""));
//	printf("%d\n", printf("%s\n", "ioèπop"));
//	ft_putstr("☆\n");
//	printf("%s\n", "☆");
//	printf("%d\n", printf("%10.2s\n", "thus"));
	return (0);
}
