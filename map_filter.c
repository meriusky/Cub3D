/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:16:32 by mehernan          #+#    #+#             */
/*   Updated: 2024/11/26 15:30:04 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
int		map_line_check(char *line, t_mapinfo *mapinfo)
{
	int i;

	i = 0;
	printf("entro en map_line_checker\n");
	while(line[i])
	{
		if(line[i] == '1' || line[i] == '0' || line[i] == ' ')
			i++;
		else if(line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
				|| line[i] == 'W')
		{
			printf("char encontrado: %c\n", line[i]);
			if(sto_finder(line[i], mapinfo) == 1)
				return(1);
		}
		else
		{
			printf("MAP ERROR: something is not supposed to be there🐛\n");
			return(1);
		}
	}
	return(0);
}

void	fill_map(char *line, t_mapinfo *mapinfo)
{
	int i;
	int j;

	i = 0;
	j = 0;
//	printf("entro en fill_map\n");
	while(mapinfo->map[j])
	{
		mapinfo->map[j] = malloc(sizeof(char) * (strlen(line) + 1));
		while(mapinfo->map[j][i])
		{
//			printf("holaaaaa\n");
			if(map_line_check(line, mapinfo) == 1)
				error_free(mapinfo, line);
		//	printf("holitaaaaa\n");
			while(line[i])
			{
				mapinfo->map[j][i] = line[i];//tengo que anyadir el /0 al final e cada str?
				i++;
			}
		}
		printf("linea copiada a **map: %s\n", mapinfo->map[j]);
		j++;
	}
}

void	take_map(char *line, t_mapinfo *mapinfo)
{
	printf("entro en take_map\n");
//	count_map
	fill_map(line, mapinfo);
	max_line(mapinfo);
	initial_pos_player(line, mapinfo);
	printf("everything fooll👌\n");	
}
/* Archivo donde se verificara si el mapa es correcto y se guardara la informacion
 * necesaria en la estructura.
 *
 * Hacemos un pequenyo checkeo para antes de hacer el floodfill. Vamos a meter
 * linea por linea antes mirando que lo unico que haya sea 0, 1, ' ' y NSWE.
 * Tendremos que tener un checkeo pequenyo para asegurarnos que no hay dos
 * personajes y que las letras son las correctas.
 *
 * Seguidamente cuando toda la **map este completa vamos a crear una funcion
 * simple con la que checkearemos los extremos del mapa y la letra.
 *
 * 👇Primero conseguiremos las rows con un simple 👇
 * int rows = 0;
 * while(map[rows])
 * 	rows++;
 *👇segundo recoremos **map👇
 int j = 0;
 int i = 0;
 while(map[j])
 {
 	while(map[j][i])
	{
		if(map[j][i] == '0')
		{
			if(i == 0 || j == 0 || i = ft_strlen(map[j]) - 1 || j = rows
				|| map[j][i+1] == ' ' || map[j+1][i] == ' ' || map[j][i-1] == ' '
					|| map[j-1][i] == ' ')
				error_free();
		}
		i++;
	}
	j++;
 }

 Lo que estamos controlando es primero si es cero y nos encontramos es
 alguna linea delimitante (linea 0, columna 0, ultima linea o ultima columna)
 Luego miramos que no haya ningun espacio al rededor, ya que si el cero
 no esta en una zona delimitante puede ser que haya un espacio, si lo hay ERROR.
👇lo tercero seria comprobar la letra (que ya sabemos que es correcta) que no👇
tenga espacios al rededor. Esto lo lograriamos con el mismo if que antes*/
