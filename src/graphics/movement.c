/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:51:41 by frankgar          #+#    #+#             */
/*   Updated: 2025/01/16 10:56:00 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
			map_x = game->pl.pos_x + x;
			map_y = *new_y + y;
			if (game->map.map[map_y][map_x] == '1')
				*new_y = get_closest_to_wall(game->pl.pos_y, *new_y);
			map_x = *new_x + x;
			map_y = game->pl.pos_y + y;
			if (game->map.map[map_y][map_x] == '1')
				*new_x = get_closest_to_wall(game->pl.pos_x, *new_x);
			x += 0.01;
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
			map_x = *new_x + x;
			map_y = *new_y + y;
			if (game->map.map[map_y][map_x] == '1')
			{
				*new_y = get_closest_to_wall(game->pl.pos_y, *new_y);
				*new_x = get_closest_to_wall(game->pl.pos_x, *new_x);
			}
			x += 0.01;
		}
		y += 0.01;
	}
}

int	movement(t_game *game, double move_angle)
{
	double	new_x;
	double	new_y;

	new_x = game->pl.pos_x;
	new_y = game->pl.pos_y;
	if (move_angle >= 0)
	{
		new_x += (MOVE_STEP * cos(move_angle * M_PI / 180.0));
		new_y -= (MOVE_STEP * sin(move_angle * M_PI / 180.0));
		get_moves(game, &new_x, &new_y);
		check_colisions(game, &new_x, &new_y);
	}
	game->pl.pos_x = new_x;
	game->pl.pos_y = new_y;
	return (1);
}

double	get_movement_angle(t_game *game, int *key_set)
{
	double	move_angle;
	double	move[4];

	game->pl.pova += (game->pl.pova < 0) * 360;
	game->pl.pova -= (game->pl.pova >= 360) * 360;
	move_angle = game->pl.pova;
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
	return (move_angle);
}
