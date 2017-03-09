/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_struct_uo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 12:02:24 by amacieje          #+#    #+#             */
/*   Updated: 2017/03/08 15:18:25 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flags			*ft_flags_struct_uo(const char *format, int *i, int j)
{
	t_flags		*flags;

	flags = ft_memalloc(sizeof(t_flags));
	while (ft_strchr(".123456789hljz", format[*i]) == NULL && *i < j)
	{
		if (format[*i] == '#')
			flags->sharp = 1;
		if (format[*i] == '0')
			flags->zero = 1;
		if (format[*i] == '-')
			flags->minus = 1;
		if (format[*i] == '.')
			flags->zero = 0;
		*i = *i + 1;
	}
	if (flags->minus == 1)
		flags->zero = 0;
	return (flags);
}
