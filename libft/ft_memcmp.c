/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:29:38 by amacieje          #+#    #+#             */
/*   Updated: 2016/12/02 15:16:55 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src;
	unsigned char	*dest;
	size_t			i;

	src = (unsigned char *)s1;
	dest = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (src[i] != dest[i])
			return (src[i] - dest[i]);
		i++;
	}
	return (0);
}
