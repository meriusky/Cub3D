# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 14:41:41 by mehernan          #+#    #+#              #
#    Updated: 2025/01/13 12:30:23 by mehernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
FLAGS = -Wall -Werror -Wextra -O3 -g -fsanitize=address 
INCLUDES = -I ./inc/\
           -I ./libft/\
		   -I ./MLX42/include/MLX42/

SRC = main.c filter.c store_mapinfo.c \
	   store_colors.c error_management.c map_filter.c store_map.c \
	   map_lines.c path_checker.c color_checker.c parsing.c graphics.c \
	   graphics_utils.c inits.c movement.c 

DIR_SRC = ./src
DIR_OBJ = $(DIR_SRC)/obj
OBJ = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))
DEP = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.d))

all: dir $(NAME)

dir:
	cmake ./MLX42 -B ./MLX42/build/ && make -C ./MLX42/build/ -j4 --no-print-directory
	make -C ./libft --no-print-directory
	mkdir -p $(DIR_OBJ)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c Makefile
	$(CC) -MMD $(FLAGS)  -c $< -o $@ $(INCLUDES)

$(NAME): $(OBJ) ./libft/libft.a ./MLX42/build/libmlx42.a 
	$(CC) $(FLAGS) $(OBJ) -Iinclude -ldl -lglfw -pthread -lm ./libft/libft.a ./MLX42/build/libmlx42.a -o $@ $(INCLUDES)
	echo "$(NAME) Created :D"

clean:
	rm -rf $(DIR_OBJ)
	rm -rf ./MLX42/build
	make clean -C ./libft/ --no-print-directory 
	echo "DEPENDENCIES Erased :D"

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft/ --no-print-directory 
	echo "EVERYTHING Erased D:"

re: fclean all

-include $(DEP)

.PHONY: fclean all clean re dir
