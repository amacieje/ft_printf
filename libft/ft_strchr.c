/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:55:28 by amacieje          #+#    #+#             */
/*   Updated: 2017/05/09 13:12:22 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	char	*copy;
	int		i;
	int		j;

	copy = (char *)s;
	i = 0;
	while (copy[i])
		i++;
	j = 0;
	while (j <= i)
	{
		if (copy[j] == c)
			return (&copy[j]);
		j++;
	}
	return (NULL);
}
