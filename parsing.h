/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:23:56 by mehernan          #+#    #+#             */
/*   Updated: 2024/11/21 19:54:00 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>// creo que no hace falta lo puse por el open

typedef struct s_mapinfo
{
	char				*north;
	char				*south;
	char				*west;
	char				*east;
	char				*floor;
	char				*ceiling;
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
void	path_checker(t_mapinfo *mapinfo, char *line);


#endif
