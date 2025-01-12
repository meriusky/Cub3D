/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:23:56 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/12 18:06:58 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
/*
# define NORTH 90
# define EAST 0
# define SOUTH 270
# define WEST 180*/

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_mapinfo
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
	int		check;
	char	**map;
	int		max_x;
	int		max_y;
	int		stx;
	int		sty;
	int		sto;
}	t_mapinfo;

void	sorter(char *line, t_mapinfo *mapinfo);
void	sorting_for_sorte(char *line, t_mapinfo mapinfo, int i);
void	north_texture(char *line, t_mapinfo *mapinfo, int i);
void	south_texture(char *line, t_mapinfo *mapinfo, int i);
void	west_texture(char *line, t_mapinfo *mapinfo, int i);
void	east_texture(char *line, t_mapinfo *mapinfo, int i);
void	floor_color(char *line, t_mapinfo *mapinfo, int i);
void	ceiling_color(char *line, t_mapinfo *mapinfo, int i);
int		rgb_checker(char *line, int i);
void	error_free(t_mapinfo *mapinfo, char *line);
void	path_checker( char *line);
void	count_map_lines(t_mapinfo *mapinfo, char *line);
void	take_map(t_mapinfo *mapinfo);
void	max_line(t_mapinfo *mapinfo);
int		sto_finder(char c, t_mapinfo *mapinfo);
void	initial_pos_player(t_mapinfo *mapinfo);
int		map_line_checker(t_mapinfo *mapinfo);
void	rgb_space(char *line, int i);

#endif
