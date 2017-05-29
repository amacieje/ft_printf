/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:47:22 by amacieje          #+#    #+#             */
/*   Updated: 2016/12/01 17:19:03 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_isneg(int *n, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

char		*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		m;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	m = n;
	i = 2;
	neg = 0;
	ft_isneg(&n, &neg);
	while ((m /= 10))
		i++;
	i = i + neg;
	if (!(s = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	s[--i] = '\0';
	while (i--)
	{
		s[i] = n % 10 + 48;
		n /= 10;
	}
	if (neg)
		s[0] = '-';
	return (s);
}
