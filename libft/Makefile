# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 22:12:27 by yjaadoun          #+#    #+#              #
#    Updated: 2023/04/20 05:47:40 by wlahyani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = ft_atoi.c			\
		ft_isalpha.c	\
		ft_memchr.c		\
		ft_memset.c		\
		ft_strlcat.c	\
		ft_strnstr.c	\
		ft_bzero.c		\
		ft_isascii.c	\
		ft_memcmp.c		\
		ft_strchr.c		\
		ft_strlcpy.c	\
		ft_strrchr.c	\
		ft_calloc.c		\
	 	ft_isdigit.c	\
	 	ft_memcpy.c		\
		ft_strdup.c		\
		ft_strlen.c		\
		ft_substr.c 	\
		ft_isalnum.c	\
		ft_isprint.c	\
		ft_memmove.c	\
		ft_strncmp.c	\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_itoa.c 		\
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_split.c		\
		ft_split1.c		\

CC = cc

CFLAGS = -Wall -Wextra -Werror 

NAME = libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

clean: 
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
