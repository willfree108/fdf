/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:30:40 by wipariso          #+#    #+#             */
/*   Updated: 2015/12/14 15:08:59 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strtrim(char const *s)
{
	int		cpt;
	int		len;
	char	*ptr;
	char	*head;

	cpt = 0;
	if (*s == 0)
		return (ft_strnew(0));
	len = ft_strlen(s) - 1;
	while (s[cpt] == ' ' || s[cpt] == '\n' || s[cpt] == '\t')
		cpt++;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	if (len - cpt < 0)
		return (ft_strnew(0));
	ptr = ft_strnew(len - cpt + 1);
	if (!ptr)
		return (NULL);
	head = ptr;
	while (cpt < len + 1)
		*ptr++ = s[cpt++];
	return (head);
}
