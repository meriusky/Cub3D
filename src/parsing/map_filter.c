/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:16:32 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/26 17:21:28 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	space_dealer(t_mapinfo *mapinfo, int i, int j)
{
	if (ft_strchr("0NESW", mapinfo->map[j][i]))
	{
		if (i == 0 || j == 0 || j + 1 == mapinfo->max_y || \
			(!ft_strchr("10NEWS", mapinfo->map[j][i + 1]) || \
			!ft_strchr("10NEWS", mapinfo->map[j][i - 1]) || \
			!ft_strchr("10NEWS", mapinfo->map[j + 1][i]) || \
			!ft_strchr("10NEWS", mapinfo->map[j - 1][i])))
			error_free(mapinfo, NULL, "ERROR: Map not closed");
	}
}

void	map_line_checker(t_mapinfo *mapinfo)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (mapinfo->map && mapinfo->map[++j])
	{
		i = 0;
		while (mapinfo->map[j][i])
		{
			if (ft_strchr("10 \n", mapinfo->map[j][i]))
				space_dealer(mapinfo, i, j);
			else if (ft_strchr("NESW", mapinfo->map[j][i]))
			{
				space_dealer(mapinfo, i, j);
				if (sto_finder(mapinfo->map[j][i], mapinfo) == 1)
					error_free(mapinfo, NULL, "ERROR: More then one player");
			}
			else
				error_free(mapinfo, NULL, "ERROR: Unexpected content in map");
			i++;
		}
	}
}

void	take_map(t_mapinfo *mapinfo)
{
	map_line_checker(mapinfo);
	max_line(mapinfo);
	initial_pos_player(mapinfo);
}
