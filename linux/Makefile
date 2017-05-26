# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wipariso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 16:09:18 by wipariso          #+#    #+#              #
#    Updated: 2016/06/25 16:52:02 by wipariso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

NAME_SRC = main.c \
	get.c \
	fill.c \
	ft_tabiter.c \
	hook.c \
	draw.c \
	calc.c \
	iter_v.c \
	add_v.c \
	ft_strtol.c \
	valid.c \
	rot.c \
	t.c

NAME_OBJ = $(NAME_SRC:.c=.o)
NAME_INC = fdf.h

PATH_SRC = ./src/
PATH_OBJ = ./obj/
PATH_INC = ./inc/
PATH_LIBFT = ./libft/
PATH_LIBX = ./libx/

CC = gcc
CFLAGS = -g

SRC = $(addprefix $(PATH_SRC),$(NAME_SRC))
OBJ = $(addprefix $(PATH_OBJ),$(NAME_OBJ))
INC = $(addprefix -I,$(PATH_INC))
LIBX = $(addprefix -L,$(PATH_LIBX))
LIBX +=	-L/usr/X13/lib -lXext -lX11 -lmlx -lm
LIBFT = $(addprefix -L,$(PATH_LIBFT))

all: $(NAME)

$(NAME): make_lib $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(inc) libft/libft.a $(LIBX)

$(PATH_OBJ)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJ)
	@$(CC) $(CFLAGS) -c $< $ -o $@ $(INC)

make_lib:
	@make -C $(PATH_LIBX) -f Makefile.gen
	@make -C $(PATH_LIBFT)

clean:
	@/bin/rm -rf $(PATH_OBJ)
	@make -C $(PATH_LIBX) -f Makefile.gen clean
	@make -C $(PATH_LIBFT) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(PATH_LIBFT) fclean

re: fclean all

norm:
	@norminette $(SRC)
	@norminette $(INC)

.PHONY: all clean fclean re make_lib norm
