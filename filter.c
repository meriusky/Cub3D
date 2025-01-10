/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:09:04 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/10 16:50:52 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"
#include "libft/libft.h"

void	sorting_for_store(char *line, t_mapinfo *mapinfo, int i)
{
	if(line[i] == 'N')
		north_texture(line, mapinfo, i);
	else if(line[i] == 'S')
		south_texture(line, mapinfo, i);
	else if(line[i] == 'W')
		west_texture(line, mapinfo, i);
	else if(line[i] == 'E')
		east_texture(line, mapinfo, i);	
	else if(line[i] == 'F')
		floor_color(line, mapinfo, i);
	else if(line[i] == 'C')
		ceiling_color(line, mapinfo, i);
	else
		printf("ERROR: information needed not found\n");
	return ;
}

void	sorter(char *line, t_mapinfo *mapinfo)
{
	int i;

	i = 0;
	if(mapinfo->check == 6)
	{
			count_map_lines(mapinfo, line); 
			return ; //hay que salir porque sino se mete el while
	}
	while(line[i])
	{
		if(line[i] == 'S' || line[i] == 'N' || line[i] == 'E' || line[i] == 'W'
					|| line[i] == 'F' || line[i] == 'C')
		{
			mapinfo->check++;
			if(mapinfo->check > 6)//no sirve ya se checkea que esten duplicados
			{
				printf("ERROR: map error, too many textures or colors\n");
				exit(1);
			}
			sorting_for_store(line, mapinfo, i);
			return ;
		}
		else if(line[i] == ' ' || line[i] == '\n')
			i++;
		else
		{
			printf("ERROR: map error, something is not supposed to be here: %c\n", line[i]);
			exit(1);
		}
//estoy ignorando el hecho de que podria haber letras randoms por ahi, quizas solo
//deberia ignorar los espacios pero no el resto de cosas.
//
//RESPUESTA: Hay que comprobar que no haya mierdas, como mucho espacios al inicio
//y final pero no mas, esos son los que puedes ignorar
//
//Asegurate de haber comprobado que si entran dos N,S,W,E el programa haga exit, es unERROR GRAVE	
	}
	return ;
}
