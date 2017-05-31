/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_octal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:18:49 by amacieje          #+#    #+#             */
/*   Updated: 2017/05/31 16:35:14 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int				ft_precision_zero(int width, t_flags *flags,
		t_whole_specifier *wholespec)
{
	int					i;
	int					printed;

	i = wholespec->precision;
	free(wholespec);
	i = 0;
	printed = 0;
	if (flags->sharp > 0)
		width--;
	while (i++ < width)
	{
		write(1, " ", 1);
		printed++;
	}
	if (flags->sharp > 0)
	{
		free(flags);
		write(1, "0", 1);
		return (printed + 1);
	}
	free(flags);
	return (width);
}

int						ft_unsigned_octal(uintmax_t li, const char *format,
		int i, int j)
{
	t_flags				*flags;
	t_whole_specifier	*wholespec;
	int					width;
	int					precision;
	int					printed;

	flags = NULL;
	wholespec = NULL;
	if ((flags = ft_flags_struct_uo_uh(format, &i, j)) == NULL)
		exit(-1);
	if ((width = ft_width(format, &i)) < 0)
		exit(-1);
	if ((precision = ft_precision(format, &i)) < 0 && precision != -3)
		exit(-1);
	if ((wholespec = ft_whole_spec_struct(width, precision, i, j)) == NULL)
		exit(-1);
	if (precision == -3 && li == 0)
		return ((printed = ft_precision_zero(width, flags, wholespec)));
	if ((printed = ft_cast_uo(li, flags, wholespec, format)) < 0)
		exit(-1);
	free(flags);
	free(wholespec);
	return (printed);
}
