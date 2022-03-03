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

HEADER = ../includes/push_swap.h
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar -rcs
RM = rm -f
LIBFT = ../includes/libft

MANDATORY = push_swap.c push_swap_utils.c sort_big_utils.c sort_utils.c sort.c operations.c\

OBJS = $(MANDATORY:.c=.o)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@

push_swap : $(OBJS)  libft
			gcc -o $@ $(OBJS) -L$(LIBFT) -lft

all: push_swap

libft:
	make -C $(LIBFT) bonus

clean: 
	$(RM) $(OBJS)
	make -C $(LIBFT) clean

fclean: clean 
	 $(RM) push_swap

re: fclean all

.PHONY: all clean fclean re libft