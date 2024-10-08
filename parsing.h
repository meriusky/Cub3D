/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:23:56 by mehernan          #+#    #+#             */
/*   Updated: 2024/10/08 17:56:24 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_mapinfo
{
	char				*north;
	char				*south;
	char				*west;
	char				*east;
	char				*floor;
	char				*ceiling;
//	struct s_mapinfo	*next;
}	t_mapinfo;

void	sorter(char *line, t_mapinfo *mapinfo);
void	sorting_for_sorte(char *line, t_mapinfo mapinfo, int i);
void	north_texture(char *line, t_mapinfo *mapinfo, int i);
void	south_texture(char *line, t_mapinfo *mapinfo, int i);
void	west_texture(char *line, t_mapinfo *mapinfo, int i);
void	east_texture(char *line, t_mapinfo *mapinfo, int i);
void	floor_color(char *line, t_mapinfo *mapinfo, int i);
void	ceiling_color(char *line, t_mapinfo *mapinfo, int i);
void	rgb_checker(char *line, int i);
int		ft_atoi(const char *str);


#endif

//en caso de error y que haya que liberar los mallocs
// va a dar segfault cuando inte liberar algo que no ha sido ocupado con informacion.
// Meter todo a zero con el bzero para que no de segfault y luego rellenar la lista.
//