# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wipariso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/25 19:08:45 by wipariso          #+#    #+#              #
#    Updated: 2016/06/25 19:08:47 by wipariso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc 
CFLAGS = -lmlx -framework OpenGL -framework AppKit
CPATH = src/
OPATH = obj/
HPATH = inc/ libft/ minilibx_macos/
INC = $(addprefix -I , $(HPATH))
CFILES = main.c \
		 get.c \
		 fill.c \
		 ft_tabiter.c \
		 hook.c \
		 draw.c \
		 calc.c \
		 iter_v.c \
		 add_v.c \
		 ft_strtol.c \
		 valid.c

OFILES = $(CFILES:.c=.o)
	HFILES = inc/fdf.h libft/libft.h
	OBJ = $(addprefix $(OPATH), $(OFILES))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C minilibx_macos
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)

debug: $(OBJ)
	make -C libft
	$(CC) -g $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)

$(OPATH)%.o: $(CPATH)%.c $(HFILES)
	mkdir -p $(OPATH)
	$(CC) $(CFLAGS) $(INC) $< -c -o $@

clean:
	rm -rf $(OPATH)
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
