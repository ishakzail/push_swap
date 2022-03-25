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

MANDATORY = ./src/push_swap.c ./src/push_swap_utils.c  ./src/sort_utils.c ./src/sort.c ./src/sort_big_utils.c  ./src/operations.c ./src/check.c ./src/stack_utils.c ./src/stack_utils_2.c
BONUS = ./src/checker.c ./src/get_next_line.c ./src/push_swap_utils.c  ./src/sort_utils.c ./src/sort.c ./src/sort_big_utils.c  ./src/operations.c ./src/check.c ./src/stack_utils.c ./src/stack_utils_2.c\

OBJS = $(MANDATORY:.c=.o)

OBJS_B = $(BONUS:.c=.o)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@

push_swap : $(OBJS)  libft
			$(CC) -o $@ -L$(LIBFT) $(OBJS) -lft

checker: $(OBJS_B) libft
	gcc -o $@  -L$(LIBFT) $(OBJS_B) -lft

bonus : $(NAME) checker

all: push_swap

libft:
	make -C $(LIBFT)

clean: 
	$(RM) push_swap
	make -C  $(LIBFT) fclean

fclean: clean 
	 $(RM) checker $(OBJS) $(OBJS_B)

re: fclean all

.PHONY: all clean fclean re libft bonus