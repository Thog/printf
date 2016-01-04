# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguillem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/21 12:17:37 by tguillem          #+#    #+#              #
#    Updated: 2016/01/04 16:41:21 by tguillem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wextra -Wall -Werror -I./
CC = gcc

NAME = libftprintf.a
SRC = ft_bzero.c ft_strdup.c ft_strnew.c ft_putchar.c ft_printi.c ft_printf.c

OBJ = $(SRC:.c=.o)
REMOVE = $(OBJ)

all: $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo Building $<...

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(REMOVE)

fclean: clean
	@/bin/rm -f $(NAME)

.PHONY: clean fclean re

re: fclean all
