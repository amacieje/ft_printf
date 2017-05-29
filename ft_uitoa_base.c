/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 11:45:43 by amacieje          #+#    #+#             */
/*   Updated: 2017/05/09 13:51:14 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static unsigned long long	ft_divide(unsigned long long int decimal,
		int base)
{
	unsigned long long		nb;

	nb = 0;
	while (decimal != 0)
	{
		decimal /= base;
		nb++;
	}
	return (nb);
}

char						*ft_uitoa_base(unsigned long long decimal,
		int base)
{
	char					*output;
	unsigned long long		nb;
	int						i;
	char					tab[17];

	if (base > 36 || base < 2)
		return (NULL);
	if (decimal == 0)
		return ("0");
	if (base == 10)
		return (ft_ullitoa(decimal));
	ft_strcpy(tab, "0123456789abcdef");
	nb = ft_divide(decimal, base);
	if (!(output = (char *)malloc(sizeof(char) * (nb + 1))))
		return (NULL);
	i = 1;
	while (decimal != 0)
	{
		output[nb - i++] = tab[decimal % base];
		decimal /= base;
	}
	output[nb] = '\0';
	return (output);
}
