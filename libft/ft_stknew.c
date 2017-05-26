/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stknew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 17:53:42 by wipariso          #+#    #+#             */
/*   Updated: 2015/12/09 22:52:12 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_stack		*ft_stknew(size_t size)
{
	t_stack	*stk;

	if (!(stk = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	stk->top = 0;
	stk->capacity = size;
	if (!(stk->content = (void**)malloc(sizeof(void*) * size)))
		return (NULL);
	return (stk);
}
