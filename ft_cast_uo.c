/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_uo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 14:07:40 by amacieje          #+#    #+#             */
/*   Updated: 2017/05/29 12:03:05 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_max_lenght(int lilenght, int width, int precision)
{
	int		max;

	if (width >= precision)
		max = width;
	else
		max = precision;
	if (lilenght >= max)
		return (lilenght);
	return (max);
}

static int	ft_printed(char *li, int printed, t_flags *flags,
		t_whole_specifier *wholespec)
{
	printed = ft_max_lenght(ft_strlen(li), wholespec->width,
			wholespec->precision);
	if ((wholespec->precision >= wholespec->width &&
	wholespec->precision - printed > (int)ft_strlen(li)) && flags->sharp == 1)
		printed++;
	else if (flags->sharp == 1 && printed <= (int)ft_strlen(li)
		&& li[0] != '0')
		printed++;
	if (*li != '0')
		free(li);
	return (printed);
}

int			ft_cast_uo(uintmax_t li, t_flags *flags,
		t_whole_specifier *wholespec, const char *format)
{
	char	*output;
	int		printed;
	int		i;

	i = wholespec->i;
	if (format[wholespec->j] == 'O' || format[i] == 'l')
		li = (unsigned long int)li;
	else if (format[i] == 'h' && format[i + 1] == 'h')
		li = (unsigned char)li;
	else if (format[i] == 'h' && format[i + 1] != 'h')
		li = (unsigned short int)li;
	else if (format[i] == 'z')
		li = (size_t)li;
	else if (ft_strchr("hljz", format[i]) == NULL)
		li = (unsigned int)li;
	printed = ft_printed(ft_uitoa_base(li, 8), 0, flags, wholespec);
	if (!(output = ft_memalloc(sizeof(char) * printed + 1)))
		return (-1);
	ft_memset(output, '0', printed);
	output[printed] = '\0';
	wholespec->j = printed;
	ft_fill_and_display_uo(output, ft_uitoa_base(li, 8), flags, wholespec);
	return (printed);
}
