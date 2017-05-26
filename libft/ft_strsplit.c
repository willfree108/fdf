/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:40:16 by wipariso          #+#    #+#             */
/*   Updated: 2016/06/29 15:04:03 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_strpurgechr(char const *s, char c)
{
	int		index;
	int		len;
	char	*ptr;
	char	*head;

	index = 0;
	len = ft_strlen(s);
	while (s[index] == c)
		index++;
	while (s[len] == c)
		len--;
	if (!(ptr = ft_strnew(len - index)))
		return (NULL);
	head = ptr;
	index--;
	while (index++ < len)
		if (s[index] != c || (s[index + 1] != c && index + 1 != len))
			*ptr++ = s[index];
	return (head);
}

static int	ft_nbword(char const *s, char c)
{
	int		cpt;

	cpt = 2;
	if (s == NULL)
		return (2);
	while (*s)
		if (*s++ == c)
			cpt++;
	return (cpt);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**head;
	char	*head_str;
	char	*str;

	i = 0;
	str = ft_strpurgechr(s, c);
	head_str = str;
	if (!str | !(head = (char**)malloc(sizeof(char*) * ft_nbword(str, c))))
		return (NULL);
	while (*str)
	{
		if (ft_strchr(str, c))
		{
			if (!(head[i++] = ft_strsub(str, 0, ft_strchr(str, c) - str)))
				return (NULL);
		}
		else
			head[i++] = ft_strdup(str);
		str = ft_strchr(str, c) ? ft_strchr(str, c) : str + ft_strlen(str);
		*str == c ? str++ : 0;
	}
	head[i] = 0;
	free(head_str);
	return (head);
}
