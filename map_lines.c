/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:40:11 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/13 17:07:47 by mehernan         ###   ########.fr       */
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
		error_free(mapinfo, line, "Failed to reallocate memory");
	mapinfo->map[j] = ft_strdup(line);
	if (!mapinfo->map[j])
		error_free(mapinfo, line, "Failed to allocate memory for line");
	j++;
}
