/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longitoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 14:54:29 by amacieje          #+#    #+#             */
/*   Updated: 2017/03/30 15:25:02 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static void		ft_isneg(long long int *n, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

char			*ft_longitoa(long long int n)
{
	char		*s;
	int			i;
	long int	m;
	int			neg;

	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
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
