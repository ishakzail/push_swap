# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izail <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/12 15:40:33 by izail             #+#    #+#              #
#    Updated: 2022/02/12 15:40:35 by izail            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = ./includes/push_swap.h
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar -rcs
RM = rm -f
LIBFT = ./includes/libft

NAME = push_swap

MANDATORY = ./src/push_swap.c ./src/push_swap_utils.c  ./src/sort_utils.c ./src/sort.c ./src/sort_big_utils.c  ./src/operations.c\

OBJS = $(MANDATORY:.c=.o)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)  libft
			$(CC) -o $@ -L$(LIBFT) $(OBJS) -lft

all: $(NAME)

libft:
	make -C $(LIBFT)

clean: 
	$(RM) $(NAME)
	make -C  $(LIBFT) fclean

fclean: clean 
	 $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft