/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:57:11 by frankgar          #+#    #+#             */
/*   Updated: 2024/12/27 16:56:29 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	exit_window(int value)
{
	exit(value);
}

void print_wall(t_game *game, int pos_x, int pos_y)
{
	int x;
	int	y;
	int	blck_size;

	blck_size = WALL_SIZE;
	pos_y = pos_y * blck_size;
	pos_x = pos_x * blck_size;
	y = pos_y;
	while (y <= pos_y + blck_size)
	{
		x = pos_x;
		while (x++ <= pos_x + blck_size)
		{
			mlx_put_pixel(game->img, x, y, 0xFFFFFFFF);
		}
		y++;
	}	
}

void	print_vision_ray(t_game *game, double pixel_angle)
{

}

void	graphics(t_game *game)
{
    int		y;
	int		x;
    double	start_angle;
    double	end_angle;
    double	pixel_angle;

	start_angle = (game->player.pova - FOV / 2) * M_PI / 180.0;
	end_angle = (game->player.pova + FOV / 2) * M_PI / 180.0;
	if (start_angle < 0)
		start_angle += 2 * M_PI;
	if (end_angle < 0)
		end_angle += 2 * M_PI;
	if (end_angle > 2 * M_PI)
		end_angle -= 2 * M_PI;
	
	y = -PLAYER_RADIUS - 2;
    while (y <= PLAYER_RADIUS - 2) 
	{
        x = -PLAYER_RADIUS - 2;
        while (x <= PLAYER_RADIUS - 2) 
		{
			pixel_angle = atan2(-y, x);
            if (pixel_angle < 0)
				pixel_angle += 2 * M_PI;
			if ((pixel_angle >= start_angle && pixel_angle <= end_angle)
				|| (start_angle >= end_angle 
				&& (pixel_angle >= start_angle || pixel_angle <= end_angle)))
				print_vision_ray(game, pixel_angle);	
            x++;
        }
        y++;
    }

}

void print_player(t_game *game, double pos_x, double pos_y, uint32_t color) 
{
    int		y;
	int		x;
    double	start_angle = (game->player.pova - FOV / 2) * M_PI / 180.0;
    double	end_angle = (game->player.pova + FOV / 2) * M_PI / 180.0;
    double	pixel_angle;

	if (start_angle < 0)
		start_angle += 2 * M_PI;
	if (end_angle < 0)
		end_angle += 2 * M_PI;
	if (end_angle > 2 * M_PI)
		end_angle -= 2 * M_PI;

    pos_x *= WALL_SIZE;
    pos_y *= WALL_SIZE;
	
    y = -PLAYER_RADIUS - 2;
    while (y <= PLAYER_RADIUS - 2) 
	{
        x = -PLAYER_RADIUS - 2;
        while (x <= PLAYER_RADIUS - 2) 
		{
            if (x * x + y * y <= (PLAYER_RADIUS - 2) * (PLAYER_RADIUS - 2)) 
			{
				pixel_angle = atan2(-y, x);
                if (pixel_angle < 0)
					pixel_angle += 2 * M_PI;
				if ((pixel_angle >= start_angle && pixel_angle <= end_angle)
						|| (start_angle >= end_angle && (pixel_angle >= start_angle || pixel_angle <= end_angle)))
					mlx_put_pixel(game->img, (int)pos_x + x, (int)pos_y + y, 0x000000);
                else
                    mlx_put_pixel(game->img, (int)pos_x + x, (int)pos_y + y, color);
            }
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
	x = 0;
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

double	get_closest_to_wall(double origin_pos, double new_pos)
{
	double	closest_pos_to_wall;

	closest_pos_to_wall = (double)((int)origin_pos);
	if (origin_pos > new_pos)
		closest_pos_to_wall += (PLAYER_RADIUS + 1) * 0.01;
	else if (origin_pos < new_pos)
		closest_pos_to_wall += 1 - ((PLAYER_RADIUS + 1) * 0.01);
	else
		closest_pos_to_wall = origin_pos;
	return (closest_pos_to_wall);
}

void	get_moves(t_game *game, double *new_x, double *new_y)
{
	double	x;
	double	y;
	int		map_x;
	int		map_y;

	y = -PLAYER_RADIUS * 0.01;
    while (y <= PLAYER_RADIUS * 0.01)
    {
		x = -PLAYER_RADIUS * 0.01;
    	while (x <= PLAYER_RADIUS * 0.01)
    	{
			if (x * x + y * y <= PLAYER_RADIUS * PLAYER_RADIUS * 0.01) 
			{
				map_x = game->player.pos_x + x;
				map_y = *new_y + y;
				if (game->map.map[map_y][map_x] == '1')
					*new_y = get_closest_to_wall(game->player.pos_y, *new_y);
				map_x = *new_x + x;
				map_y = game->player.pos_y + y;
				if (game->map.map[map_y][map_x] == '1')
					*new_x = get_closest_to_wall(game->player.pos_x, *new_x);
				x += 0.01;
			}
        }
		y += 0.01;
	}
}

void	check_colisions(t_game *game, double *new_x, double *new_y)
{
	double	x;
	double	y;
	int		map_x;
	int		map_y;

	y = -PLAYER_RADIUS * 0.01;
    while (y <= PLAYER_RADIUS * 0.01)
    {
		x = -PLAYER_RADIUS * 0.01;
    	while (x <= PLAYER_RADIUS * 0.01)
    	{
			if (x * x + y * y <= PLAYER_RADIUS * PLAYER_RADIUS * 0.01) 
			{
				map_x = *new_x + x;
				map_y = *new_y + y;
				if (game->map.map[map_y][map_x] == '1')
				{
					*new_y = get_closest_to_wall(game->player.pos_y, *new_y);
					*new_x = get_closest_to_wall(game->player.pos_x, *new_x);
				}
				x += 0.01;
			}
        }
		y += 0.01;
	}
}


int	movement(t_game *game, double move_angle)
{
    double new_x;
    double new_y;

    new_x = game->player.pos_x;
    new_y = game->player.pos_y;
    if (move_angle >= 0)
	{
		new_x += (MOVE_STEP * cos(move_angle * M_PI / 180.0));
    	new_y -= (MOVE_STEP * sin(move_angle * M_PI / 180.0));
		get_moves(game, &new_x, &new_y);
		check_colisions(game, &new_x, &new_y);
	}
    print_player(game, game->player.pos_x, game->player.pos_y, 0x00000000);
    game->player.pos_x = new_x;
    game->player.pos_y = new_y;
    print_player(game, game->player.pos_x, game->player.pos_y, 0xFF0000FF);
	return (1);
}

double	get_movement_angle(t_game *game, int *key_set)
{
	double	move_angle;
	double	move[4];

	game->player.pova += (game->player.pova < 0) * 360;
	game->player.pova -= (game->player.pova >= 360) * 360;
	move_angle = game->player.pova;
	move[0] = !(key_set[0] && key_set[1]) * key_set[0];
	move[1] = !(key_set[0] && key_set[1]) * key_set[1];
	move[2] = !(key_set[2] && key_set[3]) * key_set[2];
	move[3] = !(key_set[2] && key_set[3]) * key_set[3];
	move[2] -= (move[2]) * (move[0] * 0.5 + move[1] * 1.5);
	move[3] -= (move[3]) * (move[0] * 0.5 + move[1] * 1.5);
	if (!move[0] && !move[1] && !move[2] && !move[3])
		return (-1);
	move_angle += move[1] * 180;
	move_angle += move[2] * 90;
	move_angle -= move[3] * 90;
	move_angle += (move_angle < 0) * 360;
	move_angle -= (move_angle >= 360) * 360;
	game->player.dirx = cos(game->player.pova);
	game->player.diry = -sin(game->player.pova);
	return (move_angle);
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
	game->player.pova += rotation;
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
		graphics(game);
		
}
void	var_init(t_game *game)
{
	game->map.map = ft_calloc(8, sizeof(char *));
    if (!game->map.map)
        exit(printf("Error malloc\n") * 0 + 1);
    
    // Inicialización de cada fila del mapa
    game->map.map[0] = ft_strdup("11111111111111111");
    game->map.map[1] = ft_strdup("10000000000000001");
    game->map.map[2] = ft_strdup("10000000100000001");
    game->map.map[3] = ft_strdup("10000001010000001");
    game->map.map[4] = ft_strdup("10000000100000001");
    game->map.map[5] = ft_strdup("10000000000000001");
    game->map.map[6] = ft_strdup("11111111111111111");

	game->map.max_x = 17;
	game->map.max_y = 7;
	game->map.stx = 7;
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
	game->mlx = mlx_init(WIN_WITH + 1, WIN_LEN + 1, "Cub3D", RESIZE);
	game->img = mlx_new_image(game->mlx, WIN_WITH + 1, WIN_LEN + 1);
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
	//print_map(game);	
    print_player(game, game->player.pos_x, game->player.pos_y, 0xFF0000FF);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}

int main()
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	var_init(&game);
	init_window(&game);
	mlx_loop_hook(game.mlx, render_game, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	for (int i = 0; i < game.map.max_y; i++)
		free(game.map.map[i]);
	free(game.map.map);
	return (0);	
}
