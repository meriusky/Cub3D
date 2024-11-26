/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:04:21 by mehernan          #+#    #+#             */
/*   Updated: 2024/11/26 17:01:41 by mehernan         ###   ########.fr       */
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
	printf("all malloc free🕊️\n");
	exit(1);
}

int		filled_textures(t_mapinfo *mapinfo)
{
	int i;
	
	i = 0;
	printf("entro en filled textures\n");
	if(mapinfo->north != NULL)
		i++;		
	else if(mapinfo->north != NULL)
		i++;
	else if(mapinfo->south != NULL)
		i++;	
	else if(mapinfo->east != NULL)
		i++;	
	else if(mapinfo->west != NULL)
		i++;	
	else if(mapinfo->floor != NULL)
		i++;	
	else if(mapinfo->ceiling != NULL)
		i++;

	return(i);
}	
