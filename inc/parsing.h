/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:23:56 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/25 19:21:16 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_colors
{
	uint8_t		r;				// Defines the red color
	uint8_t		g;				// Defines the green color
	uint8_t		b;				// Defines the blue color
	uint8_t		a;				// Defines de alpha color (opacity)
	uint32_t	color;			// Defines the color based on the previous rgba
}	t_colors;

typedef struct s_mapinfo
{
	char		**map;			// Contains the Map
	char		*north;			// Texture North file path
	char		*south;			// Texture South file path
	char		*west;			// Texture East file path
	char		*east;			// Texture West file path
	char		*raw_floor;		// Floor color (in a string) 
	char		*raw_ceiling;	// Ceiling color (in a string) 
	t_colors	floor;			// Floor color Structure
	t_colors	ceiling;		// Ceiling color Structure 
	int			max_x;			// Max X value from map
	int			max_y;			// Max Y value from map
	int			stx;			// Initial X position from player
	int			sty;			// Initial Y position from player
	int			sto;			// Initial Player's Point Of View
	int			check;			// 
}	t_mapinfo;

/******************************** PARSING PART ********************************/

/////////////////////////////////// PARSING ////////////////////////////////////

t_mapinfo		parsing(int argc, char **argv);

/////////////////////////////// ERROR MANAGEMENT ///////////////////////////////

void			error_args(void);
void			error_free(t_mapinfo *mapinfo, char *line, char *print);

//////////////////////////////////// FILTER ////////////////////////////////////

void			sorter(char *line, t_mapinfo *mapinfo);
void			sorting_for_sorte(char *line, t_mapinfo mapinfo, int i);

////////////////////////////////// MAP FILTER //////////////////////////////////

void			map_line_checker(t_mapinfo *mapinfo);
void			take_map(t_mapinfo *mapinfo);

////////////////////////////////// MAP LINES ///////////////////////////////////

void			count_map_lines(t_mapinfo *mapinfo, char *line);

///////////////////////////////// PATH CHECKER /////////////////////////////////

void			path_checker( char *line);

///////////////////////////////// COLOR CHECKER ////////////////////////////////

void			rgb_space(char *line, int i);
void			convert_rgb(t_mapinfo *mapinfo, int rgb, int checker, char c);
int				rgb_checker(char *line, int i, t_mapinfo *mapinfo, char c);

///////////////////////////////// STORE COLORS /////////////////////////////////

void			floor_color(char *line, t_mapinfo *mapinfo, int i);
void			ceiling_color(char *line, t_mapinfo *mapinfo, int i);

/////////////////////////////////// STORE MAP //////////////////////////////////

void			max_line(t_mapinfo *mapinfo);
int				sto_finder(char c, t_mapinfo *mapinfo);
void			initial_pos_player(t_mapinfo *mapinfo);

///////////////////////////////// STORE MAPINFO ////////////////////////////////

void			north_texture(char *line, t_mapinfo *mapinfo, int i);
void			south_texture(char *line, t_mapinfo *mapinfo, int i);
void			west_texture(char *line, t_mapinfo *mapinfo, int i);
void			east_texture(char *line, t_mapinfo *mapinfo, int i);

/******************************************************************************/
#endif
