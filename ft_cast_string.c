/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 12:29:04 by amacieje          #+#    #+#             */
/*   Updated: 2017/04/21 18:34:56 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_display_wchar_t(const char *str, char *output,
		t_whole_specifier *wholespec, int minus)
{
	int		i;
	int		k;
	int		diff;

	diff = (int)ft_strlen(output) - (int)ft_strlen(str);
	i = -1;
	k = 0;
	if (minus == 0 && wholespec->precision == 0)
		while (output[++i])
			output[i] = (i < diff) ? ' ' : str[k++];
	else if (minus == 0)
		while (output[++i])
			output[i] = i < ((int)ft_strlen(output) - wholespec->precision) ?
				' ' : str[k++];
	else if (minus == 1)
	{
		while (str[++i])
			output[i] = str[i];
		if (wholespec->precision > 0)
			i = wholespec->precision;
		while (output[i])
			output[i++] = ' ';
	}
	ft_putstr(output);
}

static void	ft_display_char(const char *str, char *output,
		t_whole_specifier *wholespec, int minus)
{
	int		i;
	int		k;
	int		diff;

	diff = (int)ft_strlen(output) - (int)ft_strlen(str);
	i = -1;
	k = 0;
	if (minus == 0 && wholespec->precision == 0)
		while (output[++i])
			output[i] = (i < diff) ? ' ' : str[k++];
	else if (minus == 0)
		while (output[++i])
			output[i] = i < ((int)ft_strlen(output) - wholespec->precision) ?
				' ' : str[k++];
	else if (minus == 1)
	{
		while (str[++i])
			output[i] = str[i];
		if (wholespec->precision > 0)
			i = wholespec->precision;
		while (output[i])
			output[i++] = ' ';
	}
	ft_putstr(output);
}

static int	ft_max_lenght(const char *str, int strlenght,
		t_whole_specifier *wholespec, int k)
{
	int		max;
	int		i;

	max = wholespec->width;
	if (wholespec->width <= strlenght)
		max = strlenght;
	if (wholespec->precision > 0 && wholespec->width <= wholespec->precision
			&& wholespec->precision < strlenght)
		max = wholespec->precision;
	if (k == 0)
	{
		i = -1;
		while (str[++i])
		{
		/*	if ((unsigned)str[i - 1] > 255 && (unsigned)str[i] > 255)
				max--;
			if ((unsigned)str[i] < 0 )*/
			write(1, "U", 1);
		//	printf("%u\n", (unsigned)str[i]);
		}
	}
	return (max);
}

int			ft_cast_string(const char *str, t_flags *flags,
		t_whole_specifier *wholespec, const char *format)
{
	char	*output;
	int		printed;
	int		minus;
	size_t	strlenght;

	minus = flags->minus;
	strlenght = ft_strlen(str);
	if ((format[wholespec->j] == 'S' || format[wholespec->i] == 'l')
			&& MB_CUR_MAX <= 3)
	{
		if ((printed = ft_max_lenght(str, (int)strlenght, wholespec, 0)) == -1)
			return (-1);
	}
	else
		printed = ft_max_lenght(str, (int)strlenght, wholespec, 1);
	output = (char *)malloc(sizeof(char) * (printed + 1));
	output[printed] = '\0';
	ft_memset(output, 42, printed);
	if (format[wholespec->j] == 'S' || format[wholespec->i] == 'l')
		ft_display_wchar_t(str, output, wholespec, minus);
	else
		ft_display_char(str, output, wholespec, minus);
	return (printed);
}
