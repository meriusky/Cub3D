/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:25:28 by mehernan          #+#    #+#             */
/*   Updated: 2024/11/18 20:15:28 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

void	floor_color(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'F')
	{
		printf("📔%s\n", line);
		i++;
		while (line[i] != '\0')
		{
			if (line[i] == 32)
			{
				printf("📔espacio💫\n");
				i++;
			}
			if (line[i] >= 48 && line[i] <= 57)
			{
				printf("📔antes de entrar rgb checker\n");
				if(rgb_checker(line, i) == 0)
				{
					printf("string dentro de lista: %s\n", line);
					if(mapinfo->floor != NULL)
					{
						printf("ERROR: duplicated color\n");
						error_free(mapinfo, line);
					}
					mapinfo->floor = ft_strdup(line);
					return ;
				}
			}
			else
			{
					printf("📔ERROR: unexpected char not allowed\n");
					error_free(mapinfo, line);
			}
		}
	}
	else
	{
		printf("📔ERROR: floor color information wrong\n");
		error_free(mapinfo, line);
	}
}

void	ceiling_color(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'C')
	{
		i++;
		while (line[i] != '\0')
		{
			if (line[i] == 32)
			{
				printf("📔espacio💫\n");
				i++;
			}
			if (line[i] >= 48 && line[i] <= 57)
			{
				printf("📔antes de entrar rgb checker\n");
				if(rgb_checker(line, i) == 0)
				{
					printf("string dentro de lista: %s\n", line);
					if(mapinfo->ceiling != NULL)
					{
						printf("ERROR: duplicated color\n");
						error_free(mapinfo, line);
					}
					mapinfo->ceiling = ft_strdup(line);
					return ;
				}
			}
			else
			{
					printf("📔ERROR: unexpected char not allowed\n");
					error_free(mapinfo, line);
			}
		}
	}
	else
	{
		printf("📔ERROR: ceiling color information wrong\n");
		error_free(mapinfo, line);
	}
}
