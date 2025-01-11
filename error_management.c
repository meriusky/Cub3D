/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:04:21 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/10 18:41:27 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

void	error_free(t_mapinfo *mapinfo, char *line)
{
	free(line);
	if(mapinfo != NULL)
	{
		free(mapinfo->north);
		free(mapinfo->south);
		free(mapinfo->west);
		free(mapinfo->east);
		free(mapinfo->ceiling);
		free(mapinfo->floor);
		free(mapinfo->map);//ojo el doble puntero que quizas da problema
	}
	printf("all malloc free🕊️\n");
	exit(1);
}
/*
int		filled_textures(t_mapinfo *mapinfo)// no hace falta BORRAR 
{
	int i;
	
	i = 0;
	printf("🚨SOYUNTIL?🚨\n");
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
}	*/
