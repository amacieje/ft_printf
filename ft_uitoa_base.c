/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 11:45:43 by amacieje          #+#    #+#             */
/*   Updated: 2017/03/31 13:00:09 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static unsigned long long int      ft_divide(unsigned long long int decimal,
		int base)
{
	unsigned long long int nb;

	nb = 0;
	while (decimal != 0)
	{
		decimal /= base;
		nb++;
	}
	return (nb);
}

char            *ft_uitoa_base(unsigned long long int decimal, int base)
{
	char *output;
	unsigned long long int nb;
	int i;
	char tab[17];

	if (base > 36 || base < 2)
		return (NULL);
	if (decimal == 0)
		return ("0");
	if (base == 10)
		return (ft_ullitoa(decimal));
	ft_strcpy(tab, "0123456789abcdef");
	nb = ft_divide(decimal, base);
	output = (char *)malloc(sizeof(char) * (nb + 1));
	i = 1;
	while (decimal != 0)
	{
		output[nb - i++] = tab[decimal % base];
		decimal /= base;
	}
	output[nb] = '\0';
	return (output);
}

/*int		main()
{
	printf("%d\n", (unsigned char)922337203);
	printf("%x\n", (unsigned char)922337203);
	ft_putstr(ft_itoa_base((unsigned char)922337203, 10));
	return (0);
}*/

// free output
