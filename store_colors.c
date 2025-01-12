/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:25:28 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/04 19:30:37 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

void	floor_color(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'F')
	{
		i++;
		rgb_space(line, i);
		printf("i: %d\n", i);
		while (line[i] != '\0')
		{
			if (line[i] == ' ')
				i++;
			else if(line[i] >= 48 && line[i] <= 57)
			{
				if(rgb_checker(line, i) == 0)
				{
					if(mapinfo->floor != NULL)
					{
						printf("ERROR: duplicated color\n");
						error_free(mapinfo, line);
					}
					mapinfo->floor = ft_strdup(line);
					return ;
				}
				exit (1);
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
		rgb_space(line, i);
		while (line[i] != '\0')
		{
			if (line[i] == ' ')
				i++;
			else if (line[i] >= 48 && line[i] <= 57)
			{
				if(rgb_checker(line, i) == 0)
				{
					if(mapinfo->ceiling != NULL)
					{
						printf("ERROR: duplicated color\n");
						error_free(mapinfo, line);
					}
					mapinfo->ceiling = ft_strdup(line);
					return ;
				}
				exit (1);
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
