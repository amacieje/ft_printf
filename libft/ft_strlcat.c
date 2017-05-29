/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:29:38 by amacieje          #+#    #+#             */
/*   Updated: 2016/12/02 11:45:45 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	n;

	j = 0;
	n = ft_strlen(dst) + 1;
	i = n - 1;
	if (size < n)
		return (ft_strlen(src) + size);
	while (j < (size - n) && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (n + ft_strlen(src) - 1);
}
