/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:40:11 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/12 18:00:52 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

void	count_map_lines(t_mapinfo *mapinfo, char *line)
{
	static int	j = 0;

	if (j == 0 && line[0] == '\n')
		return ;
	mapinfo->map = ft_double_realloc(mapinfo->map, (j + 2) * sizeof(char *));
	if (!mapinfo->map)
	{
		printf("Failed to reallocate memory\n");
		error_free(mapinfo, line);
	}
	mapinfo->map[j] = ft_strdup(line);
	if (!mapinfo->map[j])
	{
		printf("Failed to allocate memory for line\n");
		error_free(mapinfo, line);
	}
	j++;
}
