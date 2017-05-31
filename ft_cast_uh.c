/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_uh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 11:27:42 by amacieje          #+#    #+#             */
/*   Updated: 2017/05/31 13:39:24 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

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
	int		lilenght;
	int		cpy;

	lilenght = (int)ft_strlen(li);
	printed = ft_max_lenght(lilenght, wholespec->width,
		wholespec->precision);
	cpy = printed;
	if (flags->sharp != 0 && li[0] != '0')
	{
		if (cpy < lilenght + 2)
			printed++;
		if (wholespec->precision != -3 && cpy <= wholespec->precision + 1)
			printed++;
		if (wholespec->width <= wholespec->precision
				&& wholespec->precision > lilenght + 1)
			printed++;
		if (wholespec->precision == -3 && wholespec->width <= lilenght)
			printed++;
		if (printed < lilenght + 2)
			printed++;
	}
//	if (*li != '0')
//		free(li);
	return (printed);
}

static char	*ft_hexa_shift(char *li, const char *format, int j)
{
	int		i;

	i = 0;
	if (format[j] == 'X' && li[i] != '0')
		while (li[i])
		{
			li[i] = ft_toupper(li[i]);
			i++;
		}
	return (li);
}

int			ft_cast_uh(uintmax_t li, t_flags *flags,
		t_whole_specifier *wholespec, const char *format)
{
	char	*output;
	int		printed;
	int		i;

	i = wholespec->i;
	if (format[i] == 'l' && format[i + 1] == 'l')
		li = (unsigned long long int)li;
	else if (format[i] == 'h' && format[i + 1] == 'h')
		li = (unsigned char)li;
	else if (format[i] == 'h' && format[i + 1] != 'h')
		li = (unsigned short int)li;
	else if (format[i] == 'z')
		li = (size_t)li;
	else if (ft_strchr("hljz", format[i]) == NULL)
		li = (unsigned int)li;
	printed = ft_printed(ft_uitoa_base(li, 16), 0, flags, wholespec);
	if (!(output = ft_memalloc(sizeof(char) * printed + 1)))
		return (-1);
	ft_memset(output, '0', printed);
	output[printed] = '\0';
	i = wholespec->j;
	wholespec->j = printed;
	ft_fill_and_display_uh(output, ft_hexa_shift(ft_uitoa_base(li, 16),
		format, i), flags, wholespec);
	return (printed);
}
