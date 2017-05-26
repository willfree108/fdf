/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:46:41 by wipariso          #+#    #+#             */
/*   Updated: 2015/12/09 19:15:14 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_stkclean(t_stack *head)
{
	while (head->top)
	{
		free(head->content[head->top]);
		head->content[head->top] = NULL;
		head->top -= 1;
	}
	free(head->content);
	head->content = NULL;
}
