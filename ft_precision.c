/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:41:47 by amacieje          #+#    #+#             */
/*   Updated: 2017/03/03 15:10:27 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_precision(const char *format, int *i)
{
	int		start;
	int		end;
	int		k;
	char	*precision;

	if (format[*i] != '.')
		return (0);
	*i = *i + 1;
	start = *i;
	while (ft_isdigit(format[*i]))
		*i = *i + 1;
	end = *i;
	if (!(precision = (char *)malloc(sizeof(char) * (end - start + 1))))
		return (-1);
	k = end - start;
	precision[k] = '\0';
	while (end >= start)
		precision[k--] = format[end--];
	return (ft_atoi(precision));
}
