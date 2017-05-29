/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:06:08 by amacieje          #+#    #+#             */
/*   Updated: 2016/12/02 15:16:25 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char		*s;
	unsigned char	*t;
	size_t			i;

	s = src;
	t = dst;
	i = 0;
	while (i < n)
	{
		t[i] = s[i];
		if (s[i] == c)
			return (t + i + 1);
		i++;
	}
	return (NULL);
}
