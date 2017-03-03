/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:05:21 by amacieje          #+#    #+#             */
/*   Updated: 2017/03/03 15:11:14 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flags			*ft_flags_struct(const char *format, int *i, int j)
{
	t_flags		*flags;

	flags = ft_memalloc(sizeof(t_flags));
	while (ft_strchr(".123456789", format[*i]) == NULL && *i < j)
	{
		if (format[*i] == '#')
			flags->sharp = 1;
		if (format[*i] == '0')
			flags->zero = 1;
		if (format[*i] == ' ')
			flags->space = 1;
		if (format[*i] == '+')
			flags->plus = 1;
		if (format[*i] == '-')
			flags->minus = 1;
		if (format[*i] == '.')
			flags->zero = 0;
		*i = *i + 1;
	}
	if (flags->plus == 1)
		flags->space = 0;
	if (flags->minus == 1)
		flags->zero = 0;
	return (flags);
}
