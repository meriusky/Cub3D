# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 14:41:41 by mehernan          #+#    #+#              #
#    Updated: 2025/01/25 19:13:13 by frankgar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
FLAGS = -Wall -Werror -Wextra -O3 -g -fsanitize=address 
INCLUDES = -I ./inc/\
           -I ./inc/libft/\
		   -I ./inc/MLX42/include/MLX42/

SRC = 	main.c inits.c \
		parsing/filter.c parsing/store_mapinfo.c \
		parsing/store_colors.c parsing/error_management.c parsing/map_filter.c \
		parsing/store_map.c parsing/map_lines.c parsing/path_checker.c \
		parsing/color_checker.c parsing/parsing.c \
		graphics/graphics.c graphics/graphics_utils.c graphics/movement.c 

DIR_SRC = src
DIR_OBJ = $(DIR_SRC)/obj
OBJ = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))
DEP = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.d))

all: dir $(NAME)

dir:
	cmake ./inc/MLX42 -B ./inc/MLX42/build/ && make -C ./inc/MLX42/build/ -j4 --no-print-directory
	make -C ./inc/libft --no-print-directory
	mkdir -p $(DIR_OBJ)
	mkdir -p $(DIR_OBJ)/parsing
	mkdir -p $(DIR_OBJ)/graphics

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c Makefile
	$(CC) -MMD $(FLAGS)  -c $< -o $@ $(INCLUDES)

$(NAME): $(OBJ) ./inc/libft/libft.a ./inc/MLX42/build/libmlx42.a 
	$(CC) $(FLAGS) $(OBJ) -Iinclude -ldl -lglfw -pthread -lm ./inc/libft/libft.a ./inc/MLX42/build/libmlx42.a -o $@ $(INCLUDES)
	echo "$(NAME) Created :D"

clean:
	rm -rf $(DIR_OBJ)
	rm -rf ./inc/MLX42/build
	make clean -C ./inc/libft/ --no-print-directory 
	echo "DEPENDENCIES Erased :D"

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./inc/libft/ --no-print-directory 
	echo "EVERYTHING Erased D:"

push:
ifndef COMMIT
	echo "Error: La variable COMMIT no está definida. Usa 'make push COMMIT=\"mensaje\"'"
else
	make fclean -C ./
	git add .
	git commit -m "$(COMMIT)"
	git push	
endif

re: fclean all

-include $(DEP)

.PHONY: fclean all clean re dir
.SILENT:
