/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:01:24 by frankgar          #+#    #+#             */
/*   Updated: 2024/12/27 16:30:21 by frankgar         ###   ########.fr       */
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

# define ROT_SPEED 5
# define MOVE_STEP 0.1
# define FOV 60

# define WIN_WITH 1701
# define WIN_LEN 701
# define PLAYER_RADIUS 15
# define WALL_SIZE 100

typedef struct s_mapinfo
{
//	char		*north;
//	char		*south;
//	char		*west;
//	char		*east;
//	char		*floor;
//	char		*ceiling;
	char		**map; // Mapa
	int			max_x; // Valor máximo X del mapa
	int			max_y; // Valor máximo Y del mapa
	int			stx;   // Posición Inicial del Personaje en X
	int			sty;   // Posición Inicial del Personaje en Y 
	char		sto;   // Posición Inicial que apunta el Persoanje
}	t_mapinfo;

typedef struct s_player
{
//	double	ppd;	// Projection Plane Distance
//	double	angs;   // Angular step
	double	pos_x;  // Position in x
	double	pos_y;  // Position in y
	double	pova;   // Point of view angle
	double	dirx;	// cos(pova)
	double	diry;	// -sin(pova)
}	t_player;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_player	player;
	t_mapinfo	map;
}	t_game;


/*
typedef struct s_program
{
	t_gameinfo	*game;
	t_mapinfo	*map;
}	t_program;*/

#endif
