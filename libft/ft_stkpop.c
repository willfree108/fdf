/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:42:52 by wipariso          #+#    #+#             */
/*   Updated: 2015/12/09 22:09:55 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_stkpop(t_stack *head)
{
	void	*content;

	if (head->top == 0)
		return (NULL);
	content = head->content[head->top];
	head->content[head->top] = NULL;
	head->top -= 1;
	return (content);
}
