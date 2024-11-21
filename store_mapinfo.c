/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_mapinfo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:23:26 by mehernan          #+#    #+#             */
/*   Updated: 2024/11/21 19:59:57 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
void	north_texture(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O')
	{
		i = i + 2;
		printf("entro 1r if: %c\n", line[i]);
		while (line[i] != '\n')
		{
			printf("dentro while: %c\n", line[i]);
			if (line[i] == ' ' || line[i] == '	')
				i++;
			else if ((line[i] == '.' && line[i + 1] == '/') && line[i + 2] != '\0')
			{
				printf("dentro else if: %c\n", line[i]);
				if(mapinfo->north != NULL)
				{
					printf("ERROR: duplicated texture\n");
					error_free(mapinfo, line);
				}
				path_checker(mapinfo, line); 
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
	if (line[i] == 'S' && line[i + 1] == 'O')
	{
		i = i + 2;
		printf("entro 1r if: %c\n", line[i]);
		while (line[i] != '\n')
		{
			printf("dentro while: %c\n", line[i]);
			if (line[i] == ' ' || line[i] == '	')
				i++;
			else if ((line[i] == '.' && line[i + 1] == '/') && line[i + 2] != '\0')
			{
				printf("dentro else if: %c\n", line[i]);
				if(mapinfo->south != NULL)
				{
					printf("ERROR: duplicated texture\n");
					error_free(mapinfo, line);
				}
				path_checker(mapinfo, line); 
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
		printf("entro 1r if: %c\n", line[i]);
		while (line[i] != '\n')
		{
			printf("dentro while: %c\n", line[i]);
			if (line[i] == ' ' || line[i] == '	')
				i++;
			else if ((line[i] == '.' && line[i + 1] == '/') && line[i + 2] != '\0')
			{
				printf("dentro else if: %c\n", line[i]);
				if(mapinfo->west != NULL)
				{
					printf("ERROR: duplicated texture\n");
					error_free(mapinfo, line);
				}
				path_checker(mapinfo, line);
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
		printf("entro 1r if: %c\n", line[i]);
		while (line[i] != '\n')
		{
			printf("dentro while: %c\n", line[i]);
			if (line[i] == ' ' || line[i] == '	')
				i++;
			else if ((line[i] == '.' && line[i + 1] == '/') && line[i + 2] != '\0')
			{
				printf("dentro else if: %c\n", line[i]);
				if(mapinfo->east != NULL)
				{
					printf("ERROR: duplicated texture\n");
					error_free(mapinfo, line);
				}
				path_checker(mapinfo, line);
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

