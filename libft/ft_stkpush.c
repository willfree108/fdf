/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 17:47:07 by wipariso          #+#    #+#             */
/*   Updated: 2015/12/09 19:11:14 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stkpush(t_stack *head, void *content)
{
	if (head->capacity == head->top)
		return ;
	head->top += 1;
	head->content[head->top] = content;
}
