/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 12:22:43 by amacieje          #+#    #+#             */
/*   Updated: 2017/03/30 15:25:06 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

char			*ft_ullitoa(unsigned long long int n)
{
	char					*s;
	int						i;
	unsigned long long int	m;

	m = n;
	i = 2;
	while ((m /= 10))
		i++;
	if (!(s = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	s[--i] = '\0';
	while (i--)
	{
		s[i] = n % 10 + 48;
		n /= 10;
	}
	return (s);
}
