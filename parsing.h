/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:23:56 by mehernan          #+#    #+#             */
/*   Updated: 2024/11/26 13:00:19 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>// creo que no hace falta pero lo puse por el open

typedef struct s_mapinfo
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
	char	**map; // Mapa
	int		max_x; // Valor máximo X del mapa
	int		max_y; // Valor máximo Y del mapa
	int		stx;   // Posición Inicial del Personaje en X
	int		sty;   // Posición Inicial del Personaje en Y 
	char	sto;   // Posición Inicial que apunta el Persoanje
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
//void	path_checker(t_mapinfo *mapinfo, char *line); // comentado por testeo
int		filled_textures(t_mapinfo *mapinfo);
//☝️funcion que checkea cuando tenemos lo necesario para pasar a mirar el mapa☝️
void	take_map(char *line, t_mapinfo *mapinfo);
//void	fill_map(char *line, t_mapinfo *mapinfo); no hace falta que este,
//ya que se una en el mismo filr





#endif
