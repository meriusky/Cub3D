/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:01:24 by frankgar          #+#    #+#             */
/*   Updated: 2024/11/23 11:29:09 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "MLX42.h"
# include <stdio.h>
# include <fcntl.h>

# define RESIZE 0

# define WIN_WITH 3840
# define WIN_LEN 1960
# define RENDER_WITH WIN_WITH - 1
# define RENDER_LEN WIN_LEN - 1

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
//	int 	bs;     // Block size
//	int 	vh;     // View height
//	double	fov;    // Field of view
//	double	ppd;	// Projection Plane Distance
//	double	angs;   // Angular step
//	int		lins;   // Linear speed
//	double	rots;   // Rotation speed
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
	t_mapinfo	*map;
}	t_game;




/*
typedef struct s_program
{
	t_gameinfo	*game;
	t_mapinfo	*map;
}	t_program;*/

#endif
