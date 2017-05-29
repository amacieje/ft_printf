/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 19:40:27 by amacieje          #+#    #+#             */
/*   Updated: 2017/01/09 11:00:15 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*cat;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	cat = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!cat)
		return (NULL);
	i = -1;
	while (s1[++i])
		cat[i] = s1[i];
	j = -1;
	while (s2[++j])
		cat[i + j] = s2[j];
	cat[i + j] = '\0';
	return (cat);
}
