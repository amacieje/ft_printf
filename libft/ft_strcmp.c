/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:22:45 by amacieje          #+#    #+#             */
/*   Updated: 2016/11/29 18:56:24 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			n = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i);
			return (n);
		}
		i++;
	}
	return (n);
}
