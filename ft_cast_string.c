/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 12:29:04 by amacieje          #+#    #+#             */
/*   Updated: 2017/05/31 14:33:11 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_display_wchar_t(wchar_t *str, int strlenght,
		int *printed, int minus)
{
	int			i;

	i = -1;
	if (minus == 0)
	{
		while (++i < *printed - strlenght)
			write(1, " ", 1);
		i = -1;
		while (str[++i])
			ft_printf("%C", str[i]);
	}
	else
	{
		while (str[++i])
			ft_printf("%C", str[i]);
		i = 0;
		while (i++ < *printed - strlenght)
			write(1, " ", 1);
	}
}

static int		ft_max_lenght(const char *str, int strlenght,
		t_whole_specifier *wholespec, int k)
{
	int			max;
	int			i;
	wchar_t		*widestr;

	max = wholespec->width;
	if (wholespec->width <= strlenght && ((wholespec->width <=
		wholespec->precision && (wholespec->precision >= strlenght ||
			wholespec->precision < 1)) || wholespec->precision < 1))
		max = strlenght;
	if (wholespec->precision > 0 && wholespec->width <= wholespec->precision
			&& wholespec->precision < strlenght)
		max = wholespec->precision;
	if (k == 0)
	{
		widestr = (wchar_t *)str;
		i = -1;
		while (widestr[++i])
			if ((int)widestr[i] > 255)
				return (-1);
	}
	if (strlenght == 0)
		wholespec->precision = 0;
	return (max);
}

static void		ft_wildstr_lenght(wchar_t *wildstr, size_t *strlenght, int i)
{
	char		*wildindex;
	int			len;

	wildindex = ft_uitoa_base((unsigned int)wildstr[i], 2);
	len = ft_strlen(wildindex);
	if (len < 8)
		*strlenght = *strlenght + 1;
	else if (len < 12)
		*strlenght = *strlenght + 2;
	else if (len < 17)
		*strlenght = *strlenght + 3;
	else
		*strlenght = *strlenght + 4;
	free(wildindex);
}

static size_t	ft_strlenght(const char *str, t_whole_specifier *wholespec,
		const char *format)
{
	wchar_t		*wildstr;
	size_t		strlenght;
	int			i;

	strlenght = 0;
	if (format[wholespec->j] == 'S' || format[wholespec->i] == 'l')
	{
		wildstr = (wchar_t *)str;
		i = -1;
		while (wildstr[++i])
			ft_wildstr_lenght(wildstr, &strlenght, i);
		return (strlenght);
	}
	while (str[strlenght])
		strlenght++;
	return (strlenght);
}

int				ft_cast_string(const char *str, t_flags *flags,
		t_whole_specifier *wholespec, const char *format)
{
	char		*output;
	int			printed;
	int			minus;
	size_t		strlenght;

	minus = flags->minus;
	strlenght = ft_strlenght(str, wholespec, format);
	if ((format[wholespec->j] == 'S' || format[wholespec->i] == 'l')
			&& MB_CUR_MAX <= 3)
	{
		if ((printed = ft_max_lenght(str, (int)strlenght,
						wholespec, 0)) == -1)
			return (-1);
	}
	else
		printed = ft_max_lenght(str, (int)strlenght, wholespec, 1);
	output = (char *)malloc(sizeof(char) * (printed + 1));
	output[printed] = '\0';
	ft_memset(output, ' ', printed);
	if (format[wholespec->j] == 'S' || format[wholespec->i] == 'l')
		ft_display_wchar_t((wchar_t *)str, strlenght, &printed, minus);
	else
		ft_display_char(str, output, wholespec, minus);
	free(output);
	return (printed);
}
