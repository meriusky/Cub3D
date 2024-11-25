/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:04:21 by mehernan          #+#    #+#             */
/*   Updated: 2024/11/25 16:16:39 by mehernan         ###   ########.fr       */
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
/*
void	path_checker(t_mapinfo *mapinfo, char *line)
{
	int c;
	char *path;

	path = ft_strchr(line, '/');
	printf("path: %s\n", path);
	c = open(path, O_RDONLY);
	if(c == -1)
	{
		printf("ERROR: wrong path\n");
		error_free(mapinfo, line);
	}
	else
		return ;
}*/

int		premap_checker(t_mapinfo *mapinfo)
{
	int i
	
	int = 0
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
