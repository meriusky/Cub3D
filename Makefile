# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 14:41:41 by mehernan          #+#    #+#              #
#    Updated: 2024/09/30 18:04:11 by mehernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = parsing_cub3D

CC = gcc

SRCS = main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

BUFFER_SIZE = 1000
CFLAGS = -Werror -Wextra -Wall -MMD -D BUFFER_SIZE=$(BUFFER_SIZE) -I libft -I get_next_line

LDFLAGS = -Llibft #-l get_next_line -l ft

LIBFT_PATH = libft/libft.a
GNL_PATH = get_next_line/get_next_line.c

# Color definitions
GREEN = \033[32m
RESET = \033[0m

all: 
	@$(MAKE) $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(GREEN)Parsing compiled!🩷$(RESET)"
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME)

$(LIBFT):
	@make -C libft

clean:
	rm -f $(OBJS)
	rm -f $(DEPS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
