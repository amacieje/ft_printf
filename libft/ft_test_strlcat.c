/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:14:06 by amacieje          #+#    #+#             */
/*   Updated: 2016/12/02 15:04:41 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_test_strlcat(int size)
{
	char	*src;
	char	*dst;
	size_t	i;

	src = ft_strnew(7);
	dst = ft_strnew(20);
	src = "2Code4U";
	dst = "42Born";
	i = 0;
	ft_putstr("ft_strlcat return value : ");
	ft_putnbr(ft_strlcat(dst, src, size));
	ft_putstr("\ndst after ft_strlcat : ");
	ft_putstr(dst);
	ft_putstr("\ndst casted in int : ");
	while (i <= ft_strlen(dst))
	{
		ft_putnbr(dst[i]);
		ft_putstr(" ");
		i++;
	}
	ft_putstr("\n");
	return (0);
}
