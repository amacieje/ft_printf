/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 10:30:54 by amacieje          #+#    #+#             */
/*   Updated: 2017/04/21 18:34:46 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int						ft_string(const char *str, const char *format,
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
	if ((wholespec = ft_whole_spec_struct(width, precision, i, j)) == NULL)
		exit(-1);
	if ((printed = ft_cast_string(str, flags, wholespec, format)) < 0)
		return (-1);
	free(flags);
	free(wholespec);
	return (printed);
}
