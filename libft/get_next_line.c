/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 22:01:21 by wipariso          #+#    #+#             */
/*   Updated: 2016/06/25 18:54:57 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static t_node		*ft_nodechr(t_node *node, int fd)
{
	if (node)
	{
		if (fd == node->fd)
			return (node);
		else if (fd < node->fd)
			return (ft_nodechr(node->left, fd));
		else
			return (ft_nodechr(node->right, fd));
	}
	else
		return (0);
}

static void			ft_nodeadd(t_node **root, int fd)
{
	if (!*(root))
	{
		*root = (t_node*)ft_memalloc(sizeof(t_node));
		(*root)->fd = fd;
		(*root)->el = ft_strnew(0);
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if (fd < (*root)->fd)
		ft_nodeadd(&(*root)->left, fd);
	else if (fd > (*root)->fd)
		ft_nodeadd(&(*root)->right, fd);
}

static t_node		*ft_nodedel(t_node *root, int fd)
{
	t_node			*tmp;

	if (!root)
		return (root);
	root->left = fd < root->fd ? ft_nodedel(root->left, fd) : root->left;
	root->right = fd > root->fd ? ft_nodedel(root->right, fd) : root->right;
	if (fd == root->fd)
	{
		if (!root->left || !root->right)
		{
			tmp = !root->left ? root->right : root->left;
			root->el ? free(root->el) : 0;
			root->el = NULL;
			free(root);
			root = NULL;
			return (tmp);
		}
		tmp = root->right;
		while (tmp->left != NULL)
			tmp = tmp->left;
		root->fd = tmp->fd;
		root->right = ft_nodedel(root->right, tmp->fd);
	}
	return (root);
}

int					get_next_line(const int fd, char **line)
{
	t_node			*n;
	static t_node	*root = NULL;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;

	n = ft_nodechr(root, fd);
	while (((!root || (n ? (!(ft_strchr(n->el, '\n'))) : 1)) &&
				(ret = read(fd, buf, BUFF_SIZE))))
	{
		!n ? ft_nodeadd(&root, fd) : 0;
		n = ft_nodechr(root, fd);
		tmp = n->el;
		n->el = ft_strjoin(n->el, ft_memset(buf + ret, 0, 1) - ret);
		ft_strdel(&tmp);
	}
	if (ret == -1 || fd < 0 || !line || (!n && !ret))
		return (!n && !ret ? 0 : -1);
	*line = ret ? ft_strsub(n->el, 0, ft_strchr(n->el, '\n')
			- n->el) : ft_strdup(n->el);
	tmp = n->el;
	n->el = ret ? ft_strdup(ft_strchr(n->el, '\n') + 1) : ft_strnew(0);
	ft_strdel(&tmp);
	root = *(n->el) == 0 && ret != BUFF_SIZE ? ft_nodedel(root, fd) : root;
	return (1);
}
