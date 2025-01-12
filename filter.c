/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:09:04 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/12 17:41:03 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"
#include "libft/libft.h"

void	sorting_for_store(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'N')
		north_texture(line, mapinfo, i);
	else if (line[i] == 'S')
		south_texture(line, mapinfo, i);
	else if (line[i] == 'W')
		west_texture(line, mapinfo, i);
	else if (line[i] == 'E')
		east_texture(line, mapinfo, i);
	else if (line[i] == 'F')
		floor_color(line, mapinfo, i);
	else if (line[i] == 'C')
		ceiling_color(line, mapinfo, i);
	else
		printf("ERROR: information needed not found\n");
	return ;
}

void	sorter(char *line, t_mapinfo *mapinfo)
{
	int	i;

	i = 0;
	if (mapinfo->check == 6)
	{
		count_map_lines(mapinfo, line);
		return ;
	}
	while (line[i])
	{
		if (line[i] == 'S' || line[i] == 'N' || line[i] == 'E' || line[i] == 'W'
			|| line[i] == 'F' || line[i] == 'C')
		{
			mapinfo->check++;
			if (mapinfo->check > 6)
			{
				printf("ERROR: map error, too many textures or colors\n");
				exit(1);
			}
			sorting_for_store(line, mapinfo, i);
			return ;
		}
		else if (line[i] == ' ' || line[i] == '\n')
			i++;
		else
		{
			printf("ERROR: map error, char no allowed: %c\n", line[i]);
			exit(1);
		}
	}
	return ;
}
