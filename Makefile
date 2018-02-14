# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anboscan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/12 16:28:39 by anboscan          #+#    #+#              #
#    Updated: 2018/02/12 17:26:28 by anboscan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET=fdf
CC=gcc
FLAGS=-Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
OBJ=*.o
SRC=*.c
LIBFT=libft.a

TARGET: *.c 
	@make -C libft/
	@$(CC) $(SRC) -I fdf.h -I libft/libft.h libft/libft.a $(FLAGS) -o $(TARGET)
	@echo "./fdf [map]"

clean:
		@make -C libft/ clean
		@rm fdf
		@echo "clean executed"

fclean: clean
		@make -C libft/ fclean
		@echo "fclean executed"

re: fclean TARGET
	@echo "re executed"
