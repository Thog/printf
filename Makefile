# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguillem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/21 12:17:37 by tguillem          #+#    #+#              #
#    Updated: 2016/03/10 10:56:09 by tguillem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -I./includes
CC = gcc

NAME = libftprintf.a
LIB = libft
DEP = ft_memalloc.c ft_bzero.c ft_strlen.c ft_min.c ft_max.c \
	  ft_isdigit.c ft_strchr.c ft_putchar.c ft_putwchar.c \
	  ft_putstr.c ft_putwstr.c ft_wstrlen.c ft_putnbrbase.c \
	  ft_tolower.c ft_putchar_fd.c ft_putstr_fd.c
SRC = ft_printf.c internal_printf.c utils.c parser.c manager_base.c \
	  manage_str.c manage_wstr.c manage_number.c manage_specials.c \
	  ft_printu.c ft_nbrlen.c


SRCDIR = src
OUTDIR = out

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
DEPOBJ = $(addprefix $(LIB)/, $(DEP:.c=.o)) 
OBJ = $(addprefix $(OUTDIR)/, $(SRC:.c=.o))
all: $(NAME)

$(NAME): mkOut $(OBJ)
	@(cd $(LIB) && $(MAKE))
	@ar rc $(NAME) $(OBJ) $(DEPOBJ)
	@ranlib $(NAME)
$(OUTDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -o $@ -c $? $(CFLAGS) -I./libft

mkOut:
	@mkdir -p $(OUTDIR)

clean:
	@(cd $(LIB) && $(MAKE) $@)
	@rm -f $(OBJ)
	@rm -rf $(OUTDIR)

fclean: clean
	@(cd $(LIB) && $(MAKE) $@)
	@rm -f $(NAME)

.PHONY: clean fclean re

re: fclean all
