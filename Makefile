# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lteng <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 18:46:17 by lteng             #+#    #+#              #
#    Updated: 2024/03/24 19:25:08 by lteng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = algo_util_1.c algo_util_2.c algorithm.c free.c initialisation.c \
	input_checker.c input_duplicate.c list_utils.c operations_a.c \
	operations_ab.c operations_b.c push_swap.c

OBJS = $(SRCS:.c=.o)
CC = cc -g
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
RM = rm -rf

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	$(RM) $(OBJS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
