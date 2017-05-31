/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_and_display_uh.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 11:43:52 by amacieje          #+#    #+#             */
/*   Updated: 2017/05/31 13:35:49 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_left_align(char *output, char *li, t_flags *flags,
		t_whole_specifier *wholespec)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (flags->sharp != 0 && li[0] != '0')
	{
		output[i++] = '0';
		output[i++] = (flags->sharp == 2) ? 'X' : 'x';
	}
	if (wholespec->precision > (int)ft_strlen(li))
		while (j < (int)(wholespec->precision - ft_strlen(li)))
		{
			output[i++] = '0';
			j++;
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
	while (k >= 0 && li[k] != 'x' && li[k] != 'X')
		output[i--] = li[k--];
	while (i >= wholespec->j - wholespec->precision)
		i--;
	if (flags->sharp != 0 && flags->zero == 0 && li[0] != '0')
	{
		output[i--] = (flags->sharp == 2) ? 'X' : 'x';
		output[i--] = '0';
	}
	if (flags->zero == 0)
	{
		i++;
		while (i > 0)
			output[--i] = ' ';
	}
	else if (flags->sharp != 0)
		output[1] = (flags->sharp == 2) ? 'X' : 'x';
	return (output);
}

void		ft_fill_and_display_uh(char *output, char *li, t_flags *flags,
		t_whole_specifier *wholespec)
{
	if (wholespec->precision > 0)
		flags->zero = 0;
	if (flags->minus == 1)
		output = ft_left_align(output, li, flags, wholespec);
	else
		output = ft_right_align(output, li, flags, wholespec);
	ft_putstr(output);
//	free(output);
//	if (*li != '0')
//		free(li);
}
