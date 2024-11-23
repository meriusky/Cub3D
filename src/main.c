/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:57:11 by frankgar          #+#    #+#             */
/*   Updated: 2024/11/23 11:29:43 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	exit_window(int value)
{
	exit(value);
}

int	render_game(t_game *game)
{
	(void) game;
	return (0);
}

void border_print(t_game game)
{
	int y = 0;
	int	x = 0;

	game.img = mlx_new_image(game.mlx, WIN_WITH, WIN_LEN);
	while (y <= RENDER_LEN)
	{
		x = 0;
		if (y == 0 || y == RENDER_LEN)
		{
			while (x <= RENDER_WITH)
			{
				mlx_put_pixel(game.img, x, y, 0xFF0000FF);
				x++;
			}
		}
		else
		{
			mlx_put_pixel(game.img, 0, y, 0xFF0000FF);
			mlx_put_pixel(game.img, RENDER_WITH, y, 0xFF0000FF);
		}
		y++;
	}
	mlx_image_to_window(game.mlx, game.img, 0, 0);
}

void	key_hook(mlx_key_data_t data, void *param)
{
	t_game	*game;

	game = param;	
	border_print(*game);
	if (data.action == MLX_RELEASE)
		return ;
	if (data.key ==  MLX_KEY_ESCAPE)
		exit_window(0);
	else if (data.key == MLX_KEY_W || data.key  == MLX_KEY_UP)
		printf("ARRIBA\n");
	else if (data.key == MLX_KEY_S || data.key  == MLX_KEY_DOWN)
		printf("ABAJO\n");
	else if (data.key == MLX_KEY_A)
		printf("IZQUIERDA\n");
	else if (data.key == MLX_KEY_D)
		printf("DERECHA\n");
	else if (data.key  == MLX_KEY_RIGHT)
		printf("ROTATE DERECHA\n");
	else if (data.key  == MLX_KEY_LEFT)
		printf("ROTATE IZQUIERDA\n");
}

int main()
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	//var_init(&game.map, &game.player);
	game.mlx = mlx_init(WIN_WITH, WIN_LEN, "Cub3D", RESIZE);
	mlx_key_hook(game.mlx, key_hook, &game);
	//mlx_loop_hook(game.mlx, render_game, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (0);	
}
