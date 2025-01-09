/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:04:21 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/09 16:52:06 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

void	error_free(t_mapinfo *mapinfo, char *line)
{
	free(line);
	free(mapinfo->north);
	free(mapinfo->south);
	free(mapinfo->west);
	free(mapinfo->east);
	free(mapinfo->ceiling);
	free(mapinfo->floor);
//	free(mapinfo->check);//creoq ue no cal
	free(mapinfo->map);//ojo el doble puntero que quizas da problema
//	free(mapinfo->max_x);
//	free(mapinfo->max_y);
//	free(mapinfo->stx
	printf("all malloc free🕊️\n");
	exit(1);
	// s'ha de fer free de mes cosetes eh...
	// potser caldire un altre funcio per els frees sense line
}
//FUTURAS COSAS A TOCAR:
//1.Poner que se pueda pasar una string en el error_free para poder eliminar printf
//2. Va a haber un error en error_free porque cuando ya se han llenado las texturas
// y colores yo no servira mas la line asi que habra un punto que se debera liberar
// solo el mapinfo con un monton de cosas. Creo que tendre que crear otra funcion.
int		filled_textures(t_mapinfo *mapinfo)// no hace falta BORRAR 
{
	int i;
	
	i = 0;
	if(mapinfo->north != NULL)
		i++;		
	if(mapinfo->south != NULL)
		i++;	
	if(mapinfo->east != NULL)
		i++;
	if(mapinfo->west != NULL)
		i++;
	if(mapinfo->floor != NULL)
		i++;
	if(mapinfo->ceiling != NULL)
		i++;
	return(i);
}	
