/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 16:54:46 by wipariso          #+#    #+#             */
/*   Updated: 2016/06/29 15:07:58 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static void		fill_line(t_vertex **v, char **word)
{
	int			n;
	static int	m = 0;

	n = 0;
	while (word[n])
	{
		add_v(v, word[n], m, n);
		n++;
	}
	m++;
}

t_vertex		*fill(char *path)
{
	int			fd;
	int			ret;
	char		*line;
	char		**word;
	t_vertex	*v;

	v = NULL;
	if ((fd = open(path, O_RDONLY)) == -1)
		return (NULL);
	while ((ret = get_next_line(fd, &line)))
	{
		if (!(word = ft_strsplit(line, ' ')))
			return (NULL);
		fill_line(&v, word);
		ft_strdel(&line);
		ft_tabiter(word, &ft_strdel);
	}
	if (ret == -1)
		return (NULL);
	close(fd);
	return (v);
}
