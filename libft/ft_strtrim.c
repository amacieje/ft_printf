/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:44:36 by amacieje          #+#    #+#             */
/*   Updated: 2016/12/01 17:13:57 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int			i;
	int			j;
	int			k;
	char		*trim;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = (int)ft_strlen(s) - 1;
	while (j > i && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j--;
	if (j < i)
		return (trim = ft_strdup(""));
	if (!(trim = (char *)malloc(sizeof(char) * (j - i + 2))))
		return (NULL);
	k = 0;
	while (i <= j)
		trim[k++] = s[i++];
	trim[k] = '\0';
	return (trim);
}
