/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:16:32 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/08 15:36:08 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
void	space_dealer(t_mapinfo *mapinfo, int i, int j)
{
	printf("entro en space_dealer\n");
	printf("char de space_dealer: %c\n", mapinfo->map[j][i]);
	if(mapinfo->map[j][i] != ' ') //|| mapinfo->map[j][i] != '\n')
	{
		printf("char dentro while: %c\n", mapinfo->map[j][i]);
//si esta en la primera linea y no es un uno, la ultima es igual
		if(mapinfo->map[j] == 0 && mapinfo->map[j][i] != 1)
		{
			printf("ERROR: This should be a one☝️\n");
		//	free(mapinfo->map); 
			return ;
			//arreglar error managemnt error_free
		}
		if(mapinfo->map[j][i] != '1')
		{
			printf("holaaaa\n");
			if(mapinfo->map[j-1][i] == ' ' || mapinfo->map[j+1][i] == ' ' 
				|| mapinfo->map[j][i-1] == ' ' || mapinfo->map[j][i+1] == ' ')
			{
				printf("ERROR: This should be a one☝️\n");
			//	free(mapinfo->map);
				return ;
			}
		}
	}
	return ;
}
int		map_line_checker(/*char *line,*/ t_mapinfo *mapinfo)
{
	int i;
	int j;

	i = 0;
	j = 0;

	printf("🍋map_line_checker\n");
	while(mapinfo->map[j])
	{
		i = 0;
		while(mapinfo->map[j][i])
		{
			if(mapinfo->map[j][i] == '1' || mapinfo->map[j][i] == '0' 
				|| mapinfo->map[j][i] == ' ' || mapinfo->map[j][i] == '\n')
			{
				space_dealer(mapinfo, i, j);
				printf("map_char🍋: %c\n", mapinfo->map[j][i]);
			}
			else if(mapinfo->map[j][i] == 'N' || mapinfo->map[j][i] == 'S' 
					|| mapinfo->map[j][i] == 'E' || mapinfo->map[j][i] == 'W')
			{
				space_dealer(mapinfo, i, j);
				printf("🍋char encontrado: %c\n", mapinfo->map[j][i]);
				if(sto_finder(mapinfo->map[j][i], mapinfo) == 1)
					return(1);
			}
			else
			{
				printf("MAP ERROR: something is not supposed to be there🐛\n");
				return(1);
			}
			i++;
		}
		j++;
	}
	return(0);
}

void	take_map(/*char *line,*/ t_mapinfo *mapinfo)
{

	printf("🍊take_map\n");
	map_line_checker(mapinfo);
	max_line(mapinfo);
	initial_pos_player(mapinfo);
	printf("🍊everything full👌\n");	
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
