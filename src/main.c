/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:57:11 by frankgar          #+#    #+#             */
/*   Updated: 2025/01/25 19:20:15 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include <parsing.h>

int	exit_window(int value)
{
	exit(value);
}

int	event_listener(mlx_t *mlx, t_game *game)
{
	int		move[4];
	double	move_angle;
	int		rotation;

	rotation = 0;
	ft_bzero(&move, sizeof(move));
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		exit_window(0);
	if (mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx, MLX_KEY_W))
		move[0] = 1;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx, MLX_KEY_S))
		move[1] = 1;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		move[2] = 1;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		move[3] = 1;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		rotation += ROT_SPEED;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		rotation -= ROT_SPEED;
	game->pl.pova += rotation;
	move_angle = get_movement_angle(game, move);
	if (move_angle != -1 || rotation)
		return (movement(game, move_angle));
	return (0);
}

void	render_game(void *param)
{
	t_game	*game;

	game = param;
	if (event_listener(game->mlx, game))
		draw_game(game);
}

int	main(int argc, char **argv)
{
	t_game		game;
	//t_mapindo	tmp_map;

	(void)argc;
	(void)argv;
	//tmp_map parsing(argc, argv);
	ft_bzero(&game, sizeof(t_game));
	var_init(&game);
	init_window(&game);
	mlx_loop_hook(game.mlx, render_game, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	exit(0);
}
