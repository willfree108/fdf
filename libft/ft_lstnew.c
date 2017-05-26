/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 21:49:20 by wipariso          #+#    #+#             */
/*   Updated: 2015/12/09 18:40:39 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*head;

	head = (t_list*)ft_memalloc(sizeof(t_list));
	if (!head)
		return (NULL);
	(*head).content_size = content_size;
	if (content)
	{
		(*head).content = ft_memalloc(content_size);
		(*head).content = ft_memcpy((*head).content, content, content_size);
	}
	else
	{
		(*head).content = NULL;
		(*head).content_size = 0;
	}
	(*head).next = NULL;
	return (head);
}
