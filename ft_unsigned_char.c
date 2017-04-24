/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 11:48:18 by amacieje          #+#    #+#             */
/*   Updated: 2017/04/14 11:08:03 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int						ft_unsigned_char(unsigned int c, const char *format,
		int i, int j)
{
	t_flags				*flags;
	t_whole_specifier	*wholespec;
	int					width;
	int					precision;
	int					printed;

	flags = NULL;
	wholespec = NULL;
	if ((flags = ft_flags_struct(format, &i, j)) == NULL)
		exit(-1);
	if ((width = ft_width(format, &i)) < 0)
		exit(-1);
	if ((precision = ft_precision(format, &i)) < 0)
		exit(-1);
	if ((wholespec = ft_whole_spec_struct(width, 0, i, j)) == NULL)
		exit(-1);
	if ((printed = ft_cast_uc(c, flags, wholespec, format)) < 0)
		return (-1);
	free(flags);
	free(wholespec);
	return (printed);
}
