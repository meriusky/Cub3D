/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:47:43 by frankgar          #+#    #+#             */
/*   Updated: 2025/01/25 19:24:07 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_textures(t_game *game)
{
	game->texture.north = mlx_load_png("sprites/texture.png");
	game->texture.south = mlx_load_png("sprites/texture.png");
	game->texture.east = mlx_load_png("sprites/texture.png");
	game->texture.west = mlx_load_png("sprites/texture.png");
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

void	var_init(t_game *game)
{
	game->map.map = ft_calloc(12, sizeof(char *));
	if (!game->map.map)
		exit(printf("Error malloc\n") * 0 + 1);
	game->map.map[0] = ft_strdup(" 111111111111111 ");
	game->map.map[1] = ft_strdup("10000000000011111");
	game->map.map[2] = ft_strdup("10111111111000111");
	game->map.map[3] = ft_strdup("11011111111010101");
	game->map.map[4] = ft_strdup("111001   10000001");
	game->map.map[5] = ft_strdup("11111111111111001");
	game->map.map[6] = ft_strdup("10010001000001001");
	game->map.map[7] = ft_strdup("10010001001001001");
	game->map.map[8] = ft_strdup("10000001001001001");
	game->map.map[9] = ft_strdup("10011001001001001");
	game->map.map[10] = ft_strdup("10111100001000001");
	game->map.map[11] = ft_strdup(" 111111111111111 ");
	game->map.max_x = 17;
	game->map.max_y = 7;
	game->map.stx = 1;
	game->map.sty = 1;
	game->map.sto = EAST;
	game->map.floor = 0x2B7C0FFF;
	game->map.ceiling = 0x00DADAFF;
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
