# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguillem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/21 12:17:37 by tguillem          #+#    #+#              #
#    Updated: 2015/12/11 13:49:02 by tguillem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wextra -Wall -Werror -I./
CC = gcc

NAME = libft.a
SRC = ft_memset.c ft_bzero.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
	  ft_strcat.c ft_strncat.c ft_strlcat.c ft_strstr.c ft_strcmp.c ft_atoi.c \
	  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_toupper.c ft_tolower.c ft_putchar.c ft_putstr.c ft_putendl.c \
	  ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	  ft_putnbr_fd.c  ft_strncmp.c ft_strnstr.c ft_strchr.c ft_strrchr.c \
	  ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	  ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
	  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
	  ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_itoa.c \
	  ft_strsplit.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
	  ft_lstiter.c ft_lstsize.c ft_lstmap.c ft_iswhitespace.c ft_isblank.c \
	  ft_strtrimch.c ft_strtrimcmp.c ft_islower.c ft_isupper.c

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
