# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 14:24:49 by saalamoo          #+#    #+#              #
#    Updated: 2022/12/10 16:29:03 by saalamoo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c	ft_isdigit.c ft_memset.c ft_strncmp.c ft_bzero.c ft_isprint.c ft_strchr.c \
ft_strnstr.c ft_calloc.c ft_memchr.c ft_strdup.c ft_strrchr.c ft_isalnum.c ft_memcmp.c \
ft_strlcat.c ft_tolower.c ft_isalpha.c ft_memcpy.c ft_strlcpy.c ft_toupper.c ft_isascii.c \
ft_memmove.c ft_strlen.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_putchar_fd.c ft_putendl_fd.c \
ft_putstr_fd.c ft_split.c ft_strjoin.c ft_strmapi.c ft_striteri.c ft_putnbr_fd.c ft_itoa.c

OBJ = $(SRC:.c=.o)

BSRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
ft_lstclear.c ft_lstiter.c ft_lstmap.c

BOBJ = $(BSRC:.c=.o)

all: $(NAME)
	
clean: 
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(BOBJ)
	ar rc $(NAME) $(BOBJ)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
