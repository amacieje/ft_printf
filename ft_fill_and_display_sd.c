/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_and_display_sd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:53:59 by amacieje          #+#    #+#             */
/*   Updated: 2017/05/29 13:35:46 by amacieje         ###   ########.fr       */
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
	if (flags->plus == 1 && li[0] != '-')
		output[i++] = '+';
	if (flags->space == 1 && li[0] != '-')
		output[i++] = ' ';
	if (wholespec->precision > (int)ft_strlen(li) ||
			(wholespec->precision >= (int)ft_strlen(li) && li[0] == '-'))
	{
		k = i;
		while (i < (int)(wholespec->precision - ft_strlen(li) + k))
			output[i++] = '0';
		k = 0;
		if (li[0] == '-')
			output[k++] = '-';
		i = (li[0] == '-') ? (i + 2) : i;
	}
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
	while (k >= 0 && li[k] != '-')
		output[i--] = li[k--];
	if (flags->zero == 0)
	{
		if (wholespec->precision >= lilenght)
			i = ft_strlen(output) - wholespec->precision - 1;
		if (flags->plus == 1 && li[0] != '-')
			output[i] = '+';
		else if (flags->plus == 1 && li[0] != '-')
			output[i--] = '+';
		if (li[0] == '-')
			output[i] = '-';
		else if (flags->plus == 0)
			i++;
		while (i > 0)
			output[--i] = ' ';
	}
	return (output);
}

void		ft_fill_and_display_sd(char *output, char *li, t_flags *flags,
		t_whole_specifier *wholespec)
{
	if (wholespec->precision > 0)
		flags->zero = 0;
	if (flags->minus == 1)
		output = ft_left_align(output, li, flags, wholespec);
	else
	{
		output = ft_right_align(output, li, flags, wholespec);
		if (flags->zero == 1)
		{
			if (li[0] == '-')
				output[0] = '-';
			else if (flags->plus == 1)
				output[0] = '+';
		}
		if (flags->space == 1 && li[0] != '-')
			output[0] = ' ';
	}
	ft_putstr(output);
}
