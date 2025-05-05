# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 15:49:22 by saalamoo          #+#    #+#              #
#    Updated: 2024/01/30 15:10:03 by saalamoo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_B = pipex_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

SRC = pipex.c main.c
SRC_B = pipex_bonus.c main_bonus.c closefds_bonus.c err_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	cd libft && make
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus: $(OBJ_B)
	cd libft && make
	$(CC) $(CFLAGS) $(OBJ_B) $(LIBFT) -o $(NAME_B)
	
clean:
	cd libft && make clean
	$(RM) $(OBJ) $(OBJ_B)

fclean: clean
	cd libft && make fclean
	$(RM) $(NAME) $(NAME_B)

re: fclean all

