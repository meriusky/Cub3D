/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:25:28 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/13 17:04:08 by mehernan         ###   ########.fr       */
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
			else if (line[i] >= 48 && line[i] <= 57)
			{
				if (rgb_checker(line, i, mapinfo, 'F') == 0)
				{
					if (mapinfo->raw_floor != NULL)
						error_free(mapinfo, line, "ERROR: duplicated color");
					mapinfo->floor.a = 255;
					mapinfo->raw_floor = ft_strdup(line);
					return ;
				}
				exit (1);
			}
			else
				error_free(mapinfo, line, "ERROR: unexpected char not allowed");
		}
	}
	else
		error_free(mapinfo, line, "ERROR: floor color information wrong");
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
				if (rgb_checker(line, i, mapinfo, 'C') == 0)
				{
					if (mapinfo->raw_ceiling != NULL)
						error_free(mapinfo, line, "ERROR: duplicated color");
					mapinfo->ceiling.a = 255;
					mapinfo->raw_ceiling = ft_strdup(line);
					return ;
				}
				exit (1);
			}
			else
				error_free(mapinfo, line, "ERROR: unexpected char not allowed");
		}
	}
	else
		error_free(mapinfo, line, "ERROR: ceiling color information wrong");
}
