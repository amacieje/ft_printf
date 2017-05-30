/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 11:58:06 by amacieje          #+#    #+#             */
/*   Updated: 2017/05/30 11:58:51 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_display_char(const char *str, char *output,
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
