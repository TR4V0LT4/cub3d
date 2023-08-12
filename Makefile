# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlahyani <wlahyani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 12:10:58 by yjaadoun          #+#    #+#              #
#    Updated: 2023/04/20 09:20:18 by wlahyani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = cub.c \
	get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c \
	parsing/cub_utiles1.c \
	parsing/map_elements.c \
	parsing/map.c \
	parsing/reading_map.c \
	parsing/errors_handler.c \
	parsing/parisng.c \
	parsing/textures.c \
	parsing/colores.c \
	drawing/2d_map.c \
	drawing/mlx_functions.c \
	drawing/window.c \
	drawing/player_movements.c \
	drawing/cast_rays.c \
	drawing/rotation.c \
	drawing/textures.c \
	drawing/iterator.c \
	drawing/init_val.c \
	drawing/cast_rays_utils.c \
	drawing/cast_rays_utiles1.c \
	
NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

OBJ =  $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft && make all
	@$(CC) $(CFLAGS) $(MLX_FLAGS) libft/libft.a $(OBJ) -o $(NAME)

clean: 
	@cd libft && make clean
	@rm -f $(OBJ)

fclean: clean
	@cd libft && make fclean
	@rm -f $(NAME)

re: fclean all
