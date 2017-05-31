/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 12:35:09 by amacieje          #+#    #+#             */
/*   Updated: 2017/05/31 13:40:17 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_width(const char *format, int *i)
{
	int		start;
	int		end;
	int		k;
	char	*width;

	start = *i;
	while (ft_isdigit(format[*i]))
		*i = *i + 1;
	end = *i;
	if (!(width = (char *)malloc(sizeof(char) * (end - start + 1))))
		return (-1);
	k = end - start;
	width[k] = '\0';
	while (end >= start)
		width[k--] = format[end--];
	k = ft_atoi(width);
//	free(width);
	return (k);
}
