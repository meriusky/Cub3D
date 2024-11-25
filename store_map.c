/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:16:32 by mehernan          #+#    #+#             */
/*   Updated: 2024/11/25 16:22:46 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
void	take_map(char *line, t_mapinfo *mapinfo)
{
	int i;

	i = 0;
	while(line[i])
	{
		if(line == ' ' || line == '\n');
			i++;
		if(mapinfo->map[0] == NULL && line[i] == '1')
	}
}
/* Archivo donde se verificara si el mapa es correcto y se guardara la informacion
 * necesaria en la estructura.
 *
 * Se esta sopesando la idea de hacerlo con el floodfill y cmo gestionar las cosas:
