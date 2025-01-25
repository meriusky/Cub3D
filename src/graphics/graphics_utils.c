/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:43:00 by frankgar          #+#    #+#             */
/*   Updated: 2025/01/25 19:02:44 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

mlx_image_t	*get_texture(t_game *game, t_ray *ray)
{
	if (ray->hit_side == 0)
	{
		if (ray->ray_angle_dx > 0)
			return (game->texture.img_e);
		else
			return (game->texture.img_w);
	}
	else
	{
		if (ray->ray_angle_dy < 0)
			return (game->texture.img_n);
		else
			return (game->texture.img_s);
	}
}

void	set_hit_info(t_game *game, t_ray *ray, double x, double y)
{
	double	dist;
	double	perp_dist;

	ray->hit_x = x;
	ray->hit_y = y;
	ray->texture = get_texture(game, ray);
	dist = sqrt(pow(x - game->pl.pos_x, 2) + pow(y - game->pl.pos_y, 2));
	perp_dist = dist * cos(ray->ray_angle - (game->pl.pova * M_PI / 180.0));
	ray->dist = dist;
	ray->perp_dist = perp_dist;
}

void	get_hit_distance(t_game *game, t_ray *ray)
{
	double	x;
	double	y;
	int		tmp_y;

	x = game->pl.pos_x;
	y = game->pl.pos_y;
	ray->ray_angle_dx = cos(ray->ray_angle);
	ray->ray_angle_dy = -sin(ray->ray_angle);
	tmp_y = (int)y;
	ray->hit_side = NO_HIT;
	while (ray->hit_side == NO_HIT)
	{
		if (game->map.map[tmp_y][(int)x] == '1')
			ray->hit_side = HIT_IN_Y;
		else if (game->map.map[(int)y][(int)x] == '1')
			ray->hit_side = HIT_IN_X;
		if (ray->hit_side == HIT_IN_X || ray->hit_side == HIT_IN_Y)
			set_hit_info(game, ray, x, y);
		tmp_y = (int)y;
		x += ray->ray_angle_dx * 0.001;
		y += ray->ray_angle_dy * 0.001;
	}
}

double	get_wall_pixel_x(t_game game, t_ray ray)
{
	double	wall_x;

	if (ray.hit_side == HIT_IN_Y)
		wall_x = (ray.hit_y - floor(ray.hit_y)) * ray.texture->width;
	else
		wall_x = (ray.hit_x - floor(ray.hit_x)) * ray.texture->width;
	if (ray.texture == game.texture.img_s || ray.texture == game.texture.img_w)
		wall_x = ray.texture->width - wall_x - 1;
	return (wall_x);
}
