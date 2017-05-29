/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:48:33 by amacieje          #+#    #+#             */
/*   Updated: 2016/12/02 10:05:26 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_list(t_list *list)
{
	while (list)
	{
		ft_putendl(list->content);
		ft_putnbr((int)(list->content_size));
		list = list->next;
	}
}
