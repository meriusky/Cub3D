/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:09:04 by mehernan          #+#    #+#             */
/*   Updated: 2024/10/08 18:05:33 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

void	rgb_checker(char *line, int i)
{
	char str[4];
	int check;
	int j;
	int rgb;

	j = 0;
	check = 0;
	while(line[i] != '\n')
	{
		if(line[i] >= '0' && line[i] <= '9')
		{
			if(j == 3)
			{
				printf("ERROR: color with more dan 3 digits\n");
				exit(1);
			}
			str[j] = line[i];
			i++;
			j++;
		}
		if(line[i] == ',' && (j >= 1 && j <= 3) && (line[i+1] >= '0' || line[i+1] <= 2))
		{
			rgb = ft_atoi(str);
			printf("%d\n", rgb);
			str[i] = '\0';
			if((rgb >= 0 && rgb <= 255) && check != 2)
			{
				str[0] = '\0';
				rgb = 0;
				j = 0;		
				i++;
				check++;
			}
			else
			{
				printf("ERROR: rgb color wrong\n");
				exit(1);
			}
		}
		else
		{
			printf("ERROR: only RGB colors allowed\n");
			exit(1);
		}
	}
	if(check != 2)
	{
		printf("ERROR: three colors are needed\n");
		exit(1);
	}

}

void	sorting_for_store(char *line, t_mapinfo *mapinfo, int i)
{
	if(line[i] == 'N')
		north_texture(line, mapinfo, i);
	if(line[i] == 'S')
		south_texture(line, mapinfo, i);
	if(line[i] == 'W')
		west_texture(line, mapinfo, i);
	if(line[i] == 'E')
		east_texture(line, mapinfo, i);	
	if(line[i] == 'F')
		floor_color(line, mapinfo, i);
	if(line[i] == 'C')
		ceiling_color(line, mapinfo, i);
	else
		printf("ERROR: information needed not found\n");
}

void	sorter(char *line, t_mapinfo *mapinfo)
{
	int i;
	int check;

	check = 0;
	i = 0;
	while(line[i])
	{
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
//deberia ignorar los espacios pero no el resto de cosas.
//
//RESPUESTA: Hay que comprobar que no haya mierdas, como mucho espacios al inicio
//y final pero no mas, esos son los que puedes ignorar
	}
}
