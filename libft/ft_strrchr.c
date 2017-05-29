/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:01:28 by amacieje          #+#    #+#             */
/*   Updated: 2016/11/16 17:22:32 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*copy;
	int		i;

	copy = (char *)s;
	i = 0;
	while (copy[i])
		i++;
	while (i >= 0)
	{
		if (copy[i] == c)
			return (&copy[i]);
		i--;
	}
	return (NULL);
}
