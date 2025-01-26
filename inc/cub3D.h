/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:01:24 by frankgar          #+#    #+#             */
/*   Updated: 2025/01/26 11:23:04 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "MLX42.h"
# include "parsing.h"
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
# define MOVE_STEP 0.2
# define FOV 60

# define WIN_WITH 1920
# define WIN_LEN 1080
# define PLAYER_RADIUS 15

# define HIT_IN_X  1
# define HIT_IN_Y  0
# define NO_HIT  -1

typedef struct s_wall
{
	int		height;				// Defines the Hegith of the wall
	int		start;				// Defines the start of the wall (from above)
	int		end;				// Defines the end of the wall (from above)
	double	y_step;				// Defines how many pixels are from the texture
	double	wall_x;				// Defines where in the x axis of texture it is
}	t_wall;

typedef struct s_ray
{
	double		ray_angle;		// Defines the angle of the ray
	double		ray_angle_dx;	// Defines the angle of the ray in the x axis
	double		ray_angle_dy;	// Defines the angle of the ray in the y axis
	double		angle_step;		// Defines how many angles are in a pixel
	double		hit_x;			// Defines the hit distance in the y axis
	double		hit_y;			// Defines the hit distance in the x axis
	double		dist;			// Defines the distance of the ray to the wall
	double		perp_dist;		// Defines the perpendicularity of t_ray.dist
	mlx_image_t	*texture;		// Defines the texture based on the hit
	int			hit_side;		// Defines which side of the wall it hit, x or y
}	t_ray;

typedef struct s_map
{
	char			**map;		// Contains the Map 
	char			*north;		// Texture North file path
	char			*south;		// Texture South file path
	char			*east;		// Texture East file path
	char			*west;		// Texture West file path
	uint32_t		floor;		// Floor Color
	uint32_t		ceiling;	// Ceiling Color
	int				max_x;		// Max X value from map
	int				max_y;		// Max Y value from map
	int				stx;		// Initial X position from player
	int				sty;		// Initial Y position from player 
	int				sto;		// Initial Player's Point Of View
}	t_map;

typedef struct s_player
{
	double	pos_x;				// Player's position in x
	double	pos_y;				// PLayer's position in y
	double	pova;				// Point of view angle
}	t_player;

typedef struct s_data
{
	mlx_texture_t	*north;		// Texture of the North sprite
	mlx_texture_t	*south;		// Texture of the South sprite
	mlx_texture_t	*east;		// Texture of the East sprite
	mlx_texture_t	*west;		// Texture of the West sprite
	mlx_image_t		*img_n;		// Image created based on the North texture
	mlx_image_t		*img_s;		// Image created based on the North texture
	mlx_image_t		*img_e;		// Image created based on the North texture
	mlx_image_t		*img_w;		// Image created based on the North texture
}	t_data;

typedef struct s_game
{
	mlx_t		*mlx;			// Mlx pointer
	mlx_image_t	*img;			// Image where we will be painting all the cub3D
	t_player	pl;				// Player's information structure
	t_map		map;			// Map's information structure
	t_data		texture;		// All Texture's informaction structure
}	t_game;

/********************************** FUNCTIONS *********************************/

//////////////////////////////////// INITS /////////////////////////////////////

void		init_textures(t_game *game);
void		var_init(t_game *game, t_mapinfo *mapinfo);
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

/******************************************************************************/

#endif
