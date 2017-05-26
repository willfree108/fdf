/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:18:10 by wipariso          #+#    #+#             */
/*   Updated: 2015/12/11 15:34:37 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *ptr;

	ptr = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!ptr)
		return (NULL);
	ptr = ft_strcat(ptr, s1);
	ptr = ft_strcat(ptr, s2);
	return (ptr);
}
