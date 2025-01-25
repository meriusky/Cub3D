/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:42:17 by frankgar          #+#    #+#             */
/*   Updated: 2025/01/18 18:42:54 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_pixel(t_game *game, int x, int y, int color)
{
	if (x >= 0 && x < WIN_WITH && y >= 0 && y < WIN_LEN)
		mlx_put_pixel(game->img, x, y, color);
}

uint32_t	get_pixel_info(mlx_image_t *texture, int pixel_index)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	r = texture->pixels[pixel_index];
	g = texture->pixels[pixel_index + 1];
	b = texture->pixels[pixel_index + 2];
	a = texture->pixels[pixel_index + 3];
	return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_texture(mlx_image_t *img, mlx_image_t *texture, int x, t_wall wall)
{
	double	tex_pos;
	int		tex_y;
	int		y;
	int		pixel_index;

	wall.y_step = (double)texture->height / wall.height;
	y = wall.start;
	tex_pos = 0;
	while (y < wall.end)
	{
		if (y > WIN_LEN)
			break ;
		tex_y = (int)tex_pos % texture->height;
		tex_pos += wall.y_step;
		pixel_index = (tex_y * texture->width + (int)wall.wall_x) * 4;
		if (y >= 0)
			mlx_put_pixel(img, x, y, get_pixel_info(texture, pixel_index));
		y++;
	}
}

void	draw_world(t_game *game, t_wall wall, int x)
{
	int	y;

	y = 0;
	while (y < wall.start)
	{
		draw_pixel(game, x, y, game->map.ceiling);
		y++;
	}
	y = wall.end;
	while (y < WIN_LEN)
	{
		draw_pixel(game, x, y, game->map.floor);
		y++;
	}
}

void	draw_game(t_game *game)
{
	int		x;
	t_wall	wall;
	t_ray	ray;

	x = WIN_WITH;
	ray.ray_angle = (game->pl.pova - (FOV / 2)) * M_PI / 180.0;
	ray.angle_step = (FOV * M_PI / 180.0) / WIN_WITH;
	while (x >= 0)
	{
		get_hit_distance(game, &ray);
		wall.height = (int)(WIN_LEN / ray.perp_dist);
		wall.start = (WIN_LEN - wall.height) / 2;
		wall.end = (WIN_LEN + wall.height) / 2;
		wall.wall_x = get_wall_pixel_x(*game, ray);
		draw_texture(game->img, ray.texture, x, wall);
		draw_world(game, wall, x);
		ray.angle_step = (FOV * M_PI / 180.0) / WIN_WITH;
		ray.ray_angle += ray.angle_step;
		x--;
	}
}
