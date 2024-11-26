/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:16:32 by mehernan          #+#    #+#             */
/*   Updated: 2024/11/26 13:00:17 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
int	sto_finder(char *line)
{
	if (mapinfo->sto != NULL)
	{
		if (c == 'N')
			mapinfo->sto == "NORTH";
		else if (c == 'S')
			mapinfo->sto == "SOUTH";
		else if (c == 'E')
			mapinfo->sto == "EAST";
		else if (c == 'W')
			mapinfo->sto == "WEST";
		return(0);
	}
	else
	{
		printf("MAP ERROR: more that one player found🤼‍♀️\n");
		return(1);
	}
}

int		map_line_check(char c)
{
	int i;

	i = 0;
	while(line[i])
	{
		if(line[i] == '1' || line[i] == '0' || line[i] == ' ')
			i++;
		else if(line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
				|| line[i] == 'W')
		{
			if(sto_finder(line[i]) == 1)
				return(1);
		}
		else
		{
			printf("MAP ERROR: something is not supposed to be there🐛\n");
			return(1)
		}
	}
	return(0);
}
void	max_line(t_mapinfo *mapinfo);
{
	int max_row;
	int max_clm;
	int j;

	max_row = 0;
	max_clm = 0;
	j = 0;
	while(map[j])
	{
		max_row = ft_strlen(map[j]);
		if(max_row < ft_strlen(map[j + 1])
			max_row = ft_strlen(map[j + 1])
		j++;
	}
	mapinfo->max_y = j;
	mapinfo->max_x = max_row;
}
void	fill_map(char *line, t_mapinfo *mapinfo)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(map[j][i])
	{
		if(map_line_check(line) == 1)
			error_free(mapinfo, line);
		while(line[i])
		{
			map[j][i] == line[i]//tengo que anyadir el /0 al final e cada str?
			i++;
		}
		printf("linea copiada a **map: %s\n", map[j]);
		j++;
	}
}
void	take_map(char *line, t_mapinfo *mapinfo)
{
	fill_map(line, mapinfo);
	max_line(mapinfo);	
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
tenga espacios al rededor. Esto lo lograriamos con el mismo if que antes
