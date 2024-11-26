/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:57:11 by frankgar          #+#    #+#             */
/*   Updated: 2024/11/26 13:03:22 by frankgar         ###   ########.fr       */
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

void print_wall(t_game *game, int pos_x, int pos_y)
{
	int x;
	int	y;
	int	blck_size_x;
	int	blck_size_y;

	blck_size_x = RENDER_WITH / game->map.max_x;
	blck_size_y = RENDER_LEN / game->map.max_y;
	pos_y = pos_y * blck_size_y;
	pos_x = pos_x * blck_size_x;
	y = pos_y;
	while (y <= pos_y + blck_size_y)
	{
		x = pos_x;
		while (x++ <= pos_x + blck_size_x)
		{
			mlx_put_pixel(game->img, x, y, 0xFFFFFFFF);
		}
		y++;
	}	
}

void print_player(t_game *game, double pos_x, double pos_y, uint32_t color)
{
	double	x;
	double	y;
	double	blck_size_x;
	double	blck_size_y;
	double	extra;

	blck_size_x = (RENDER_WITH / game->map.max_x);
	blck_size_y = (RENDER_LEN / game->map.max_y);
	extra = blck_size_y / 4;
	pos_y = ((pos_y * blck_size_y) + extra) - 0.5;
	extra = blck_size_x / 4;
	pos_x = ((pos_x * blck_size_x) + extra) - 0.5;
	y = pos_y;
	while (y <= pos_y + (blck_size_y / 2))
	{
		x = pos_x;
		while (x <= pos_x + (blck_size_x / 2))
		{
			mlx_put_pixel(game->img, x, y, color);
			x++;
		}
		y++;
	}
}

void print_map(t_game *game)
{
	int y;
	int	x;

	y = 0;
	while (y < game->map.max_y)
	{
		x = 0;
		while (x < game->map.max_x)
		{
			if (game->map.map[y][x] == '1')
				print_wall(game, x, y);
			x++;
		}
		y++;
	}
	print_player(game, game->player.pos_x, game->player.pos_y, 0xFF0000FF);
}

void	movement(t_game *game, double x, double y)
{	
	double	blck_size_x;
	double	blck_size_y;
	int	wall_y;
	int	wall_x;

	blck_size_x = (RENDER_WITH / game->map.max_x);
	blck_size_y = (RENDER_LEN / game->map.max_y);
	wall_y = 0;
	while () 
	if (x < player2.x + blck_size_x &&
    		x + (blck_size_x / 2) > player2.x &&
    		y < player2.y + blck_size_y &&
    		y + (blck_size_y / 2) > player2.y)
		return ;

	print_player(game, game->player.pos_x, game->player.pos_y, 0x00000000);
	game->player.pos_y = y;
	game->player.pos_x = x;
	print_player(game, game->player.pos_x, game->player.pos_y, 0xFF0000FF);
}

void	key_hook(mlx_key_data_t data, void *param)
{
	t_game	*game;

	game = param;	
	if (data.action == MLX_RELEASE)
		return ;
	if (data.key ==  MLX_KEY_ESCAPE)
		exit_window(0);
	else if (data.key == MLX_KEY_W || data.key  == MLX_KEY_UP)
		movement(game, game->player.pos_x, game->player.pos_y - 0.25);
	else if (data.key == MLX_KEY_S || data.key  == MLX_KEY_DOWN)
		movement(game, game->player.pos_x, game->player.pos_y + 0.25);
	else if (data.key == MLX_KEY_A)
		movement(game, game->player.pos_x - 0.25, game->player.pos_y);
	else if (data.key == MLX_KEY_D)
		movement(game, game->player.pos_x + 0.25, game->player.pos_y);
	else if (data.key  == MLX_KEY_RIGHT)
		printf("ROTATE DERECHA\n");
	else if (data.key  == MLX_KEY_LEFT)
		printf("ROTATE IZQUIERDA\n");
}

void var_init(t_game *game)
{
	game->map.map = ft_calloc(8, sizeof(char *));
    if (!game->map.map)
        exit(printf("Error malloc\n") * 0 + 1);
    
    // Inicialización de cada fila del mapa
    game->map.map[0] = ft_strdup("11111111111111111");
    game->map.map[1] = ft_strdup("10000000000000001");
    game->map.map[2] = ft_strdup("10000000100000001");
    game->map.map[3] = ft_strdup("10000001110000001");
    game->map.map[4] = ft_strdup("10000000100000001");
    game->map.map[5] = ft_strdup("10000000000000001");
    game->map.map[6] = ft_strdup("11111111111111111");

	game->map.max_x = 17;
	game->map.max_y = 7;
	game->map.stx = 3;
	game->map.sty = 4;
	game->map.sto = NORTH;
///////////////////////////////////////////////////
	game->player.pos_x = (double)game->map.stx + 0.5;
	game->player.pos_y = (double)game->map.sty + 0.5;
	game->player.pova = (double)game->map.sto;
	game->player.dirx = cos(game->player.pova);
	game->player.diry = -sin(game->player.pova);
}

void init_window(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->mlx = mlx_init(WIN_WITH, WIN_LEN, "Cub3D", RESIZE);
	game->img = mlx_new_image(game->mlx, WIN_WITH, WIN_LEN);
	while (y < game->map.max_y)
	{
		x = 0;
		while (x < game->map.max_x)
		{
			if (game->map.map[y][x] == '1')
				mlx_put_pixel(game->img, x, y, 0x00000000);
			x++;
		}
		y++;
	}
	print_map(game);	
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}

int main()
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	var_init(&game);
	init_window(&game);
	mlx_key_hook(game.mlx, key_hook, &game);
	//mlx_loop_hook(game.mlx, render_game, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (0);	
}
