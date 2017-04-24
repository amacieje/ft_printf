/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_hexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 11:25:25 by amacieje          #+#    #+#             */
/*   Updated: 2017/04/05 14:15:57 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int				ft_print_pointer(unsigned long long li,
		const char *format, int i)
{
	char	*newformat;
	char	*width;
	int		k;

	width = ft_itoa(ft_width(format, &i));
	k = ft_strlen(width);
	if (!(newformat = (char *)malloc(sizeof(char) * k + 3)) || width < 0)
		exit(-1);
	newformat[0] = '%';
	newformat[k + 2] = '\0';
	newformat[k + 1] = 's';
	if (width > 0)
		while (k > 0)
		{
			newformat[k] = width[k - 1];
			k--;
		}
	width = ft_strjoin("0x", ft_uitoa_base(li, 16));
	return (printf(newformat, width));
	//mettre ft_printf !
}

int						ft_unsigned_hexa(unsigned long long li, const char *format,
		int i, int j)
{
	t_flags				*flags;
	t_whole_specifier	*wholespec;
	int					width;
	int					precision;
	int					printed;

	flags = NULL;
	wholespec = NULL;
	if (format[j] == 'p')
		return (ft_print_pointer(li, format, i + 1));
	if ((flags = ft_flags_struct_uo_uh(format, &i, j)) == NULL)
		exit(-1);
	if ((precision = ft_precision(format, &i)) < 0)
		exit(-1);
	if ((width = ft_width(format, &i)) < 0)
		exit(-1);
	if ((wholespec = ft_whole_spec_struct(width, precision, i, j)) == NULL)
		exit(-1);
	if ((printed = ft_cast_uh((uintmax_t)li, flags, wholespec, format)) < 0)
		exit(-1);
	free(flags);
	free(wholespec);
	return (printed);
}
