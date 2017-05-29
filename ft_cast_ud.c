/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_ud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 11:29:48 by amacieje          #+#    #+#             */
/*   Updated: 2017/05/10 11:35:22 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_max_lenght(char *li, t_whole_specifier *wholespec)
{
	int		max;
	int		lilenght;

	lilenght = ft_strlen(li);
	free(li);
	if (wholespec->width >= wholespec->precision)
		max = wholespec->width;
	else
		max = wholespec->precision;
	if (lilenght >= max)
		return (lilenght);
	return (max);
}

int			ft_cast_ud(uintmax_t li, t_flags *flags,
		t_whole_specifier *wholespec, const char *format)
{
	char	*output;
	int		printed;
	int		i;

	i = wholespec->i;
	if (format[wholespec->j] == 'U' || format[i] == 'l')
		li = (unsigned long long int)li;
	else if (format[i] == 'h' && format[i + 1] == 'h')
		li = (unsigned char)li;
	else if (format[i] == 'h' && format[i + 1] != 'h')
		li = (unsigned short int)li;
	else if (format[i] == 'z')
		li = (size_t)li;
	else if (ft_strchr("hljz", format[i]) == NULL)
		li = (unsigned int)li;
	printed = ft_max_lenght(ft_ullitoa(li), wholespec);
	if (!(output = ft_memalloc(sizeof(char) * printed + 1)))
		return (-1);
	ft_memset(output, '0', printed);
	output[printed] = '\0';
	wholespec->j = printed;
	ft_fill_and_display_ud(output, ft_ullitoa(li), flags, wholespec);
	return (printed);
}
