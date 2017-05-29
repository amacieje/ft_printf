/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_hexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 11:25:25 by amacieje          #+#    #+#             */
/*   Updated: 2017/05/29 13:43:43 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int				ft_print_pointer(unsigned long long li,
		t_whole_specifier *wholespec, t_flags *flags, int i)
{
	char				*newformat;
	char				*width;
	char				*str;
	int					k;

	width = ft_itoa(wholespec->width);
	i = ft_strlen(width);
	k = flags->minus == 1 ? ft_strlen(width) + 1 : ft_strlen(width);
	if (!(newformat = (char *)malloc(sizeof(char) * k + 3)) || width < 0)
		exit(-1);
	newformat[0] = '%';
	newformat[1] = '-';
	newformat[k + 2] = '\0';
	newformat[++k] = 's';
	while (width > 0 && --k > 0 && width[--i])
		newformat[k] = width[i];
	free(width);
	str = ft_uitoa_base(li, 16);
	width = ft_strjoin("0x", str);
	k = ft_printf(newformat, width);
	free(newformat);
	if (*str != '0')
		free(str);
	free(width);
	return (k);
}

static int				ft_precision_zero(int width, char c)
{
	int					i;

	i = 0;
	if (c == 'p')
	{
		if (width < 2)
			width = 2;
		write(1, "0x", 2);
		while (i++ < width - 2)
			write(1, " ", 1);
		return (width);
	}
	while (i++ < width)
		write(1, " ", 1);
	return (width);
}

int						ft_unsigned_hexa(unsigned long long li,
		const char *format, int i, int j)
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
		return (ft_precision_zero(width, format[j]));
	if (format[j] == 'p')
		return (ft_print_pointer(li, wholespec, flags, 0));
	if ((printed = ft_cast_uh((uintmax_t)li, flags, wholespec, format)) < 0)
		exit(-1);
	free(flags);
	free(wholespec);
	return (printed);
}
