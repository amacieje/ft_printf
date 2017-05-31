/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_and_display_uo.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:16:59 by amacieje          #+#    #+#             */
/*   Updated: 2017/05/31 16:09:20 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_left_align(char *output, char *li, t_flags *flags,
		t_whole_specifier *wholespec)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (wholespec->precision > (int)ft_strlen(li))
	{
		while (i < (int)(wholespec->precision - ft_strlen(li)))
			output[i++] = '0';
		k = 0;
	}
	if (flags->sharp == 1 && wholespec->precision <= (int)ft_strlen(li))
		output[i++] = '0';
	while (li[k])
		output[i++] = li[k++];
	while (i < wholespec->j)
		output[i++] = ' ';
	return (output);
}

static char	*ft_right_align(char *output, char *li, t_flags *flags,
		t_whole_specifier *wholespec)
{
	int		i;
	int		k;
	int		lilenght;

	lilenght = (int)ft_strlen(li);
	i = wholespec->j;
	k = lilenght;
	while (k >= 0)
		output[--i] = li[--k];
	if (flags->sharp == 1)
		output[--i] = '0';
	if (flags->zero == 0)
	{
		if (wholespec->precision > lilenght)
			i = ft_strlen(output) - wholespec->precision - 1;
//		i++;
		while (i > 0)
			output[--i] = ' ';
	}
	return (output);
}

void		ft_fill_and_display_uo(char *output, char *li, t_flags *flags,
		t_whole_specifier *wholespec)
{
	if (wholespec->precision > 0)
		flags->zero = 0;
	if (flags->minus == 1)
	output = ft_left_align(output, li, flags, wholespec);
	else
		output = ft_right_align(output, li, flags, wholespec);
	ft_putstr(output);
	free(output);
	if (*li != '0')
		free(li);
}
