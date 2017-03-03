/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whole_spec_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:24:53 by amacieje          #+#    #+#             */
/*   Updated: 2017/03/03 15:07:47 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_whole_specifier		*ft_whole_spec_struct(int width, int precision,
		int i, int j)
{
	t_whole_specifier	*wholespec;

	if (!(wholespec = ft_memalloc(sizeof(t_whole_specifier))))
		return (NULL);
	wholespec->width = width;
	wholespec->precision = precision;
	wholespec->i = i;
	wholespec->j = j;
	return (wholespec);
}
