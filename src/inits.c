/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:47:43 by frankgar          #+#    #+#             */
/*   Updated: 2025/01/25 21:04:23 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_textures(t_game *game)
{
	game->texture.north = mlx_load_png(&game->map.north[2]);
	game->texture.south = mlx_load_png(&game->map.south[2]);
	game->texture.east = mlx_load_png(&game->map.east[2]);
	game->texture.west = mlx_load_png(&game->map.west[2]);
	if (!game->texture.north || !game->texture.south
		|| !game->texture.east || !game->texture.west)
	{
		printf("Error loading textures\n");
		exit(1);
	}
	game->texture.img_n = mlx_texture_to_image(game->mlx, game->texture.north);
	game->texture.img_s = mlx_texture_to_image(game->mlx, game->texture.south);
	game->texture.img_e = mlx_texture_to_image(game->mlx, game->texture.east);
	game->texture.img_w = mlx_texture_to_image(game->mlx, game->texture.west);
}

uint32_t	get_color(t_colors color)
{
	return (color.r << 24 | color.g << 16 | color.b << 8 | color.a);
}

void	var_init(t_game *game, t_mapinfo *mapinfo)
{
	game->map.map = mapinfo->map;
	game->map.max_x = mapinfo->max_x;
	game->map.max_y = mapinfo->max_y;
	game->map.stx = mapinfo->stx;
	game->map.sty = mapinfo->sty;
	game->map.sto = mapinfo->sto;
	game->map.north = mapinfo->north;
	game->map.south = mapinfo->south;
	game->map.east = mapinfo->east;
	game->map.west = mapinfo->west;
	game->map.floor = get_color(mapinfo->floor);
	game->map.ceiling = get_color(mapinfo->ceiling);
	game->pl.pos_x = (double)game->map.stx + 0.5;
	game->pl.pos_y = (double)game->map.sty + 0.5;
	game->pl.pova = (double)game->map.sto;
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init(WIN_WITH + 1, WIN_LEN + 1, "Cub3D", RESIZE);
	game->img = mlx_new_image(game->mlx, WIN_WITH + 1, WIN_LEN + 1);
	init_textures(game);
	draw_game(game);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}
