/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_uc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 11:53:58 by amacieje          #+#    #+#             */
/*   Updated: 2017/05/31 10:08:59 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_two_bytes_lc(t_mask *mask, t_flags *flags, unsigned int c,
		int k)
{
	mask->second = (c & 0b00111111) | 0b10000000;
	mask->first = ((c >> 6) & 0b00011111) | 0b11000000;
	if (flags->minus == 1)
	{
		write(1, &mask->first, 1);
		write(1, &mask->second, 1);
		while (k++ < mask->printed - 2)
			write(1, " ", 1);
		write(1, 0, 1);
	}
	else
	{
		while (k++ < mask->printed - 2)
			write(1, " ", 1);
		write(1, &mask->first, 1);
		write(1, &mask->second, 1);
		write(1, 0, 1);
	}
}

static void		ft_three_bytes_lc(t_mask *mask, t_flags *flags, unsigned int c,
		int k)
{
	mask->third = (c & 0b00111111) | 0b10000000;
	mask->second = ((c >> 6) & 0b00111111) | 0b10000000;
	mask->first = ((c >> 12) & 0b00001111) | 0b11100000;
	if (flags->minus == 1)
	{
		write(1, &mask->first, 1);
		write(1, &mask->second, 1);
		write(1, &mask->third, 1);
		while (k++ < mask->printed - 3)
			write(1, " ", 1);
		write(1, 0, 1);
	}
	else
	{
		while (k++ < mask->printed - 3)
			write(1, " ", 1);
		write(1, &mask->first, 1);
		write(1, &mask->second, 1);
		write(1, &mask->third, 1);
		write(1, 0, 1);
	}
}

static void		ft_four_bytes_lc(t_mask *mask, t_flags *flags, unsigned int c,
		int k)
{
	mask->fourth = (c & 0b00111111) | 0b10000000;
	mask->third = ((c >> 6) & 0b00111111) | 0b10000000;
	mask->second = ((c >> 12) & 0b00111111) | 0b10000000;
	mask->first = ((c >> 18) & 0b00000111) | 0b11110000;
	if (flags->minus == 1)
	{
		write(1, &mask->first, 1);
		write(1, &mask->second, 1);
		write(1, &mask->third, 1);
		write(1, &mask->fourth, 1);
		while (k++ < mask->printed - 4)
			write(1, " ", 1);
		write(1, 0, 1);
	}
	else
	{
		while (k++ < mask->printed - 4)
			write(1, " ", 1);
		write(1, &mask->first, 1);
		write(1, &mask->second, 1);
		write(1, &mask->third, 1);
		write(1, &mask->fourth, 1);
		write(1, 0, 1);
	}
}

static void		ft_display_lc(unsigned int c, t_flags *flags,
		t_whole_specifier *wholespec, int *printed)
{
	char		*binary;
	size_t		lenght;
	t_mask		*mask;

	binary = ft_uitoa_base(c, 2);
	lenght = ft_strlen(binary);
	if (!(mask = ft_memalloc(sizeof(t_mask))))
		exit(-1);
	mask->printed = *printed;
	if (lenght < 8)
		ft_display_c(c, flags, *printed);
	else if (lenght < 12)
		ft_two_bytes_lc(mask, flags, c, 0);
	else if (lenght < 17)
		ft_three_bytes_lc(mask, flags, c, 0);
	else if (lenght < 22 && lenght > 16)
		ft_four_bytes_lc(mask, flags, c, 0);
	if (c > 7 && wholespec->width == 0)
		*printed = *printed + lenght / 4 - 1;
	else if (c > 7 && wholespec->width < ((int)lenght / 4))
		*printed = lenght / 4;
	if (c > 7 && *printed == 4 && lenght == 16)
		*printed = *printed - 1;
}

int				ft_cast_uc(unsigned int c, t_flags *flags,
		t_whole_specifier *wholespec, const char *format)
{
	int			printed;
	int			i;

	i = wholespec->i;
	printed = 1;
	if (wholespec->width > 0)
		printed = wholespec->width;
	if ((format[wholespec->j] == 'C' || format[i] == 'l') && MB_CUR_MAX > 3)
		ft_display_lc(c, flags, wholespec, &printed);
	else if ((format[wholespec->j] == 'C' || format[i] == 'l')
			&& MB_CUR_MAX < 3 && c > 255)
		return (-1);
	else
		ft_display_c(c, flags, printed);
	return (printed);
}
