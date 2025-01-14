/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:01:24 by frankgar          #+#    #+#             */
/*   Updated: 2025/01/13 10:59:32 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "MLX42.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define RESIZE 0

# define NORTH 90
# define EAST 0
# define SOUTH 270
# define WEST 180

# define CLEAR_SCREEN "\x1b[1J \x1b[H"

# define ROT_SPEED 4
# define MOVE_STEP 0.1
# define FOV 60

# define WIN_WITH 1920
# define WIN_LEN 1080
# define PLAYER_RADIUS 15
//# define WALL_SIZE 10

// PARSEAR FOV NO PUEDE SER NEGATIVO

typedef struct	s_wall
{
	int		height;
	int		start;
	int		end;
	double	y_step;
	double	wall_x;

}	t_wall;

typedef struct s_ray
{
	double		ray_angle;
	double		angle_step;
	double		hit_x;
	double		hit_y;
	double		t_hit_x;
	double		t_hit_y;
	double		dist;
	double		perp_dist;
	double		ray_angle_dx;
	double		ray_angle_dy;
	mlx_image_t	*texture;
	int			side;
}	t_ray;

typedef struct s_mapinfo
{
	char			**map; // Mapa
	char			*north; // Texture North
	char			*sout; // Texture South
	char			*east; // Texture East
	char			*west; // Texture West
	uint32_t		floor;
	uint32_t		ceiling;
	int				max_x; // Valor máximo X del mapa
	int				max_y; // Valor máximo Y del mapa
	int				stx;   // Posición Inicial del Personaje en X
	int				sty;   // Posición Inicial del Personaje en Y 
	int				sto;   // Posición Inicial que apunta el Persoanje
}	t_mapinfo;

typedef struct s_player
{
	double	pos_x;  // Position in x
	double	pos_y;  // Position in y
	double	pova;   // Point of view angle
}	t_player;

typedef struct s_data
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
	mlx_image_t		*img_n;
	mlx_image_t		*img_s;
	mlx_image_t		*img_e;
	mlx_image_t		*img_w;
}	t_data;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_player	pl;
	t_mapinfo	map;
	t_data		texture;
}	t_game;

//////////////////////////////////// INITS /////////////////////////////////////

void		init_textures(t_game *game);
void		var_init(t_game *game);
void		init_window(t_game *game);

////////////////////////////////// MOVEMENT ////////////////////////////////////

double		get_closest_to_wall(double origin_pos, double new_pos);
void		get_moves(t_game *game, double *new_x, double *new_y);
void		check_colisions(t_game *game, double *new_x, double *new_y);
int			movement(t_game *game, double move_angle);
double		get_movement_angle(t_game *game, int *key_set);

////////////////////////////////// GRAPHICS ////////////////////////////////////

void		draw_pixel(t_game *game, int x, int y, int color);
void		draw_world(t_game *game, t_wall wall, int x);
uint32_t	get_pixel_info(mlx_image_t *texture, int pixel_index);
void		draw_game(t_game *game);

//////////////////////////////// GRAPHICS UTILS ////////////////////////////////

void		set_hit_info(t_game *game, t_ray *ray, double x, double y);
void		get_hit_distance(t_game *game, t_ray *ray);
double		get_wall_pixel_x(t_game game, t_ray ray);
mlx_image_t	*get_texture(t_game *game, t_ray *ray);

#endif
