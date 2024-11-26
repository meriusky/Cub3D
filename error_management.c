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
	if(mapinfo->north == NULL)
	{
		i++;		
		printf("N: i de filled: %d\n", i);
	}
	else if(mapinfo->south == NULL)
	{
		i++;	
	printf("S: i de filled: %d\n", i);
	}
	else if(mapinfo->east == NULL)
	{
		i++;
	printf("E: i de filled: %d\n", i);
	}
	else if(mapinfo->west == NULL)
	{
		i++;
		printf("W: i de filled: %d\n", i);
	}
	else if(mapinfo->floor == NULL)
	{
		i++;
	printf("F: i de filled: %d\n", i);
	}
	else if(mapinfo->ceiling == NULL)
	{
		i++;
		printf("C: i de filled: %d\n", i);
	}
	printf("i de filled FINAL: %d\n", i);
	return(i);
}	
