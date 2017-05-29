/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:01:49 by amacieje          #+#    #+#             */
/*   Updated: 2016/11/28 18:02:27 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*t;
	size_t	i;

	i = 0;
	s = (char *)src;
	t = (char *)dst;
	if (s < t)
		while ((int)(--len) >= 0)
			t[len] = s[len];
	else
		while (i < len)
		{
			t[i] = s[i];
			i++;
		}
	return (t);
}
