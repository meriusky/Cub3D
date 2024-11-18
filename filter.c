/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:09:04 by mehernan          #+#    #+#             */
/*   Updated: 2024/11/18 20:17:41 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"
#include "libft/libft.h"

int	rgb_checker(char *line, int i)
{
	char str[4];
	int check;
	int j;
	int rgb;

	j = 0;
	check = 0;
	printf("entro rgbcheck🧣\n");
	while(line[i] != '\n')
	{
		while(line[i] >= '0' && line[i] <= '9')
		{
			printf("j: %d\n", j);
			printf("numero %c\n", line[i]);
			if(j == 3)
			{
				printf("ERROR: color with more dan 3 digits🧣\n");
				exit(1);
			}
			str[j] = line[i];
			i++;
			j++;
		}
		printf("char antes del if %c\n", line[i]);
		printf("j antes del if %d\n", j);
		if((line[i] == ',' || line[i] == '\n') && (j >= 1 && j <= 3))// && (line[i+1] >= '0' || line[i+1] <= 2)) no se porque puse esto
		{
			printf("encuentro coma🏁: %c\n", line[i]);
			str[j] = '\0';
			rgb = ft_atoi(str);
			printf("num post atoi: %d\n", rgb);
			if((rgb >= 0 && rgb <= 255) && check != 3)
			{
				str[0] = '\0';
				rgb = 0;
				j = 0;		
				i++;
				check++;
				printf("all done perfect✅\n");
				if(check == 3)
				{
					printf("✅COLOR CORRECT✅\n");
					return (0);
				}
			}
			else
			{
				printf("ERROR: rgb color wrong🧣\n");
				exit(1);
			}
		}
		else
		{
			printf("ERROR: only RGB colors allowed🧣\n");
			exit(1);
		}
	}
	if(check != 3)
	{
		printf("ERROR: three colors are needed\n");
		exit(1);
	}
	return(1);
}/*
void	check_color_duplication(char letter)
{
	int	F;
	int	C;

	F = 0;
	C = 0;
	if(letter == 'F' && F != 1)
		F++;
	else if(letter == 'C' && C != 1)
		C++;
	else
	{
		printf("ERROR: duplicated colors\n");
		exit(1);
	}
}

void	check_duplication(char letter)
{
	int N;
	int S;
	int W;
	int	E;

	N = 0;
	S = 0;
	W = 0;
	E = 0;
	if(letter == 'F' || letter == 'C')
		check_color_duplication(letter);
	else if(letter == 'N' && N != 1)
		N++;
	else if(letter == 'S' && S != 1)
		S++;
	else if(letter == 'W' && W != 1)
		W++;
	else if(letter == 'E' && E != 1)
		E++;
	else
	{
		printf("ERROR: duplicated texture\n");
		exit(1);
	}
}*/

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
	int check;

	check = 0;
	i = 0;
	while(line[i])
	{
		if(line[i] == 'S' || line[i] == 'N' || line[i] == 'E' || line[i] == 'W'
					|| line[i] == 'F' || line[i] == 'C')
		{
			check = check + 1; // o simplemente check++;
			if(check > 6)
			{
				printf("ERROR: map error, too amny textures or colors\n");
				exit(1);
			}
			else
				sorting_for_store(line, mapinfo, i);
		}
		else if(line[i] == ' ' || line[i] == '\n')
			i++;
		else
		{
			printf("ERROR: map error, something is not soposed to be here:: %c\n", line[i]);
			exit(1);
		}
		return ;
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
//IMPORTANTE: crear un check por si se repiten;
