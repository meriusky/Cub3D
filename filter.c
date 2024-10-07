/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:09:04 by mehernan          #+#    #+#             */
/*   Updated: 2024/10/07 18:57:36 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

void	rgb_checker(char *line, int i)
{
	char *first;
	char *second;
	char *third;
	int check

	while(line[i] != '\n')
	{
		if(line[i] => '0' && line[i] <= '9')
		{
			if(line[i] => '1' && line[i] =< '5')

			(line[i] == ',')
		}
		else
			printf("ERROR: only RGB colors allowed\n");
	}
}
void	sorting_for_store(char *line, t_mapinfo *mapinfo, int i)
{
	if(line[i] == 'N')
		north_texture(line, mapinfo, i);
	if(line[i] == 'S')
		south_texture(line, mapnfo, i);
	if(line[i] == 'W')
		west_texture(line, mapinfo, i);
	if(line[i] == 'E')
		east_texture(line, mapnfo, i);	
	if(line[i] == 'F')
		floor_color(line, mapnfo, i);
	if(line[i] == 'C')
		ceiling_color(line, mapnfo, i);
	else
		printf("ERROR: information needed not found\n");
}
void	sorter(char *line, t_mapinfo *mapinfo)
{
	int i;
//	int check;

//	check = 6;
	i = 0;
//	printf("🚨entra a sorter\n");
	while(line[i])
	{
//		if(check == 0)
//		{
//			printf("error: too many textures or colors\n");
//			exit(1);
//		}
		if(line[i] == 'S' || line[i] == 'N' || line[i] == 'E' || line[i] == 'W'
					|| line[i] == 'F' || line[i] == 'C')
		{
			check = check + 1;
			if(check > 6)
			{
				printf("ERROR: map error, too amny textures or colors\n");
				exit(1);
			}
			else
				sorting_for_store(line, mapinfo, i);
		}
		else
			i++;
//estoy ignorando el hecho de que podria haber letras randoms por ahi, quizas solo
//deberia ignorar los espacios ero no el resto de cosas.
//
//RESPUESTA: Hay que comprobar que no haya mierdas, como mucho espacios al inicio
//y final pero no mas, esos son los que puedes ignorar
	}
}
