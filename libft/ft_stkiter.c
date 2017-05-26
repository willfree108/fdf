/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 23:00:44 by wipariso          #+#    #+#             */
/*   Updated: 2015/12/09 23:23:00 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stkiter(t_stack *head, void (*f)(void *elem))
{
	size_t cpt;

	cpt = 0;
	while (cpt < head->top)
	{
		f(head->content[cpt]);
		cpt++;
	}
}
