/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 12:29:04 by amacieje          #+#    #+#             */
/*   Updated: 2017/05/29 13:33:50 by amacieje         ###   ########.fr       */
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

static void		ft_display_char(const char *str, char *output,
		t_whole_specifier *wholespec, int minus)
{
	int			i;
	int			k;
	int			diff;
	int			min;

	diff = (int)ft_strlen(output) - (int)ft_strlen(str);
	i = -1;
	k = 0;
	min = wholespec->precision >= (int)ft_strlen(str) ? (int)ft_strlen(str)
		: wholespec->precision;
	if (minus == 0 && wholespec->precision == 0)
		while (output[++i])
			output[i] = (i < diff) ? ' ' : str[k++];
	else if (minus == 0)
		while (output[++i])
			output[i] = i < ((int)ft_strlen(output) - min) ? ' ' : str[k++];
	else if (minus == 1)
	{
		while (str[++i] && i < (int)ft_strlen(output))
			output[i] = str[i];
		i = wholespec->precision > 0 ? wholespec->precision : i;
		while (output[i] && i < (int)ft_strlen(output))
			output[i++] = ' ';
	}
	ft_putstr(output);
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
		{
			if (ft_strlen(ft_uitoa_base((unsigned int)wildstr[i], 2)) < 8)
				strlenght++;
			else if (ft_strlen(ft_uitoa_base((unsigned int)wildstr[i], 2)) < 12)
				strlenght = strlenght + 2;
			else if (ft_strlen(ft_uitoa_base((unsigned int)wildstr[i], 2)) < 17)
				strlenght = strlenght + 3;
			else
				strlenght = strlenght + 4;
		}
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
