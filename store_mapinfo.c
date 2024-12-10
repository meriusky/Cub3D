/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_mapinfo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:23:26 by mehernan          #+#    #+#             */
/*   Updated: 2024/11/26 17:00:47 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
//path_checker esta comentado porque tengo que testear y no tengo los path correctos aun
void	north_texture(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O')
	{
		i = i + 2;
		while (line[i] != '\n')
		{
			if (line[i] == ' ' || line[i] == '	')
				i++;
			else if ((line[i] == '.' && line[i + 1] == '/') && line[i + 2] != '\0')
			{
				if(mapinfo->north != NULL)
				{
					printf("ERROR: duplicated texture\n");
					error_free(mapinfo, line);
				}
//				path_checker(mapinfo, line); 
				mapinfo->north = ft_strdup(line);
				printf("✅:%s\n", line);
				return ;
			}
		}
		printf("error: wrong north texture path\n");
		error_free(mapinfo, line);
	}
	else
	{
		printf("ERROR: north textute information wrong\n");
		error_free(mapinfo, line);	
	}
}

void	south_texture(char *line, t_mapinfo *mapinfo, int i)
{
	printf("hola south\n");
	if (line[i] == 'S' && line[i + 1] == 'O')
	{
		i = i + 2;
		while (line[i] != '\n')
		{
			if (line[i] == ' ' || line[i] == '	')
				i++;
			else if ((line[i] == '.' && line[i + 1] == '/') && line[i + 2] != '\0')
			{
				if(mapinfo->south != NULL)
				{
					printf("ERROR: duplicated texture\n");
					error_free(mapinfo, line);
				}
//				path_checker(mapinfo, line); 
				mapinfo->south = ft_strdup(line);
				printf("✅:%s\n", line);
				return ;
			}
		}
		printf("error: wrong south texture path\n");
		error_free(mapinfo, line);
	}
	else
	{
		printf("ERROR: south textute information wrong\n");
		error_free(mapinfo, line);
	}
}

void	west_texture(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'W' && line[i + 1] == 'E')
	{
		i = i + 2;
		while (line[i] != '\n')
		{
			if (line[i] == ' ' || line[i] == '	')
				i++;
			else if ((line[i] == '.' && line[i + 1] == '/') && line[i + 2] != '\0')
			{
				if(mapinfo->west != NULL)
				{
					printf("ERROR: duplicated texture\n");
					error_free(mapinfo, line);
				}
//				path_checker(mapinfo, line);
				mapinfo->west = ft_strdup(line);
				printf("✅:%s\n", line);
				return ;
			}
		}
		printf("error: wrong west texture path\n");
		error_free(mapinfo, line);
	}
	else
	{
		printf("ERROR: west textute information wrong\n");
		error_free(mapinfo, line);
	}
}

void	east_texture(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'E' && line[i + 1] == 'A')
	{
		i = i + 2;
		while (line[i] != '\n')
		{
			if (line[i] == ' ' || line[i] == '	')
				i++;
			else if ((line[i] == '.' && line[i + 1] == '/') && line[i + 2] != '\0')
			{
				if(mapinfo->east != NULL)
				{
					printf("ERROR: duplicated texture\n");
					error_free(mapinfo, line);
				}
	//			path_checker(mapinfo, line);
				mapinfo->east = ft_strdup(line);
				printf("✅:%s\n", line);
				return ;
			}
		}
		printf("error: wrong east texture path\n");
		error_free(mapinfo, line);
	}
	else
	{
		printf("ERROR: east textute information wrong\n");
		error_free(mapinfo, line);
	}
}

