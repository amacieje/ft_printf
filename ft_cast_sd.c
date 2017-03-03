/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_sd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:46:39 by amacieje          #+#    #+#             */
/*   Updated: 2017/03/03 15:06:27 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_max_lenght(long int li, int width, int precision)
{
	int		max;
	int		lilenght;

	if (width >= precision)
		max = width;
	else
		max = precision;
	lilenght = ft_strlen(ft_longitoa(li));
	if (lilenght >= max)
		return (lilenght);
	return (max);
}

static int	ft_printed(long int li, int printed, t_flags *flags,
		t_whole_specifier *wholespec)
{
	printed = ft_max_lenght(li, wholespec->width, wholespec->precision);
	if ((wholespec->precision >= wholespec->width && ((li < 0 &&
	wholespec->precision >= (int)ft_strlen(ft_longitoa(li))) ||
	(flags->minus == 0 && ((li >= 0 && flags->plus == 1) || (li >= 0 &&
	flags->space == 1))) || (li > 0 && flags->plus == 1))) || (li >= 0 &&
	(flags->plus == 1 || flags->space == 1)
	&& printed == (int)ft_strlen(ft_longitoa(li))))
		printed++;
	return (printed);
}

int			ft_cast_sd(long int li, t_flags *flags,
		t_whole_specifier *wholespec, const char *format)
{
	char	*output;
	int		printed;
	int		i;

	i = wholespec->i;
	if (format[i] == 'h' && format[i + 1] == 'h')
		li = (signed char)li;
	else if (format[i] == 'h' && format[i + 1] != 'h')
		li = (short int)li;
	else if (format[i] == 'j')
		li = (intmax_t)li;
	else if (format[i] == 'z' || format[i] == 'D')
		li = (size_t)li;
	else if (ft_strchr("hljz", format[i]) == NULL)
		li = (int)li;
	printed = ft_printed(li, 0, flags, wholespec);
	if (!(output = ft_memalloc(sizeof(char) * printed + 1)))
		return (-1);
	ft_memset(output, '0', printed);
	output[printed] = '\0';
	wholespec->j = printed;
	ft_fill_and_display(output, ft_longitoa(li), flags, wholespec);
	return (printed);
}
