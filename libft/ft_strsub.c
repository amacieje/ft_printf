/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 19:07:49 by amacieje          #+#    #+#             */
/*   Updated: 2016/11/29 19:48:39 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*part;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	part = (char *)malloc(sizeof(char) * (len + 1));
	if (!part)
		return (NULL);
	i = 0;
	j = (int)start;
	while (j < ((int)start + (int)len))
	{
		part[i] = (char)(s[j]);
		i++;
		j++;
	}
	part[i] = '\0';
	return (part);
}
