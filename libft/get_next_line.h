/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 12:19:27 by wipariso          #+#    #+#             */
/*   Updated: 2016/06/25 18:09:39 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

int					get_next_line(const int fd, char**line);

typedef struct		s_node
{
	int				fd;
	char			*el;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

#endif
