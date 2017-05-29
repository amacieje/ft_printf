/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:19:43 by amacieje          #+#    #+#             */
/*   Updated: 2016/11/25 18:54:51 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;

	if (lst)
	{
		result = (t_list *)malloc(sizeof(f(lst)));
		if (!result)
			return (NULL);
		result = f(lst);
		result->next = ft_lstmap(lst->next, f);
		return (result);
	}
	return (NULL);
}
