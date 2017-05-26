/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:49:25 by wipariso          #+#    #+#             */
/*   Updated: 2015/12/11 15:19:59 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*map;

	if (!lst)
		return (NULL);
	map = f(ft_lstnew(lst->content, lst->content_size));
	head = map;
	while (lst->next)
	{
		lst = lst->next;
		map->next = f(ft_lstnew(lst->content, lst->content_size));
		map = map->next;
	}
	return (head);
}
