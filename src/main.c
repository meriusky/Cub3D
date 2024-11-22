/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:57:11 by frankgar          #+#    #+#             */
/*   Updated: 2024/11/22 12:45:52 by frankgar         ###   ########.fr       */
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

void	key_hook(mlx_key_data_t data, void *game)
{
	(void) game;
	if (data.action == MLX_RELEASE)
		return ;
	if (data.key ==  MLX_KEY_ESCAPE)
		exit_window(0);
	else if (data.key == MLX_KEY_W || data.key  == MLX_KEY_UP)
		printf("ARRIBA\n");
	else if (data.key == MLX_KEY_S || data.key  == MLX_KEY_DOWN)
		printf("ABAJO\n");
	else if (data.key == MLX_KEY_A || data.key  == MLX_KEY_LEFT)
		printf("IZQUIERDA\n");
	else if (data.key == MLX_KEY_D || data.key  == MLX_KEY_RIGHT)
		printf("DERECHA\n");
}

int main()
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	// var_init(&game.map, &game.player);
	game.win = mlx_init(WIN_WITH, WIN_LEN, "Cub3D", RESIZE);
	mlx_key_hook(game.win, key_hook, &game);
	//mlx_loop_hook(game.mlx, render_game, &game);
	mlx_loop(game.win);
	mlx_terminate(game.win);
	return (0);	
}
