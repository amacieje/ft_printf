/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 13:36:44 by amacieje          #+#    #+#             */
/*   Updated: 2017/05/05 11:19:31 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_display_c(int c, t_flags *flags, int printed)
{
	int		k;

	k = 0;
	if (flags->minus == 1)
	{
		write(1, &c, 1);
		while (k++ < printed - 1)
			write(1, " ", 1);
		write(1, 0, 1);
	}
	else
	{
		while (k++ < printed - 1)
			write(1, " ", 1);
		write(1, &c, 1);
		write(1, 0, 1);
	}
}
