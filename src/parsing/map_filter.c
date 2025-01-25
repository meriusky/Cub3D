/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:16:32 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/25 18:59:17 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	space_dealer(t_mapinfo *mapinfo, int i, int j)
{
	if (mapinfo->map[j][i] != ' ' && mapinfo->map[j][i] != '\n')
	{
		if (mapinfo->map[j][i] != '1')
		{
			if ((j == 0 && mapinfo->map[j][i] != 1) || i == 0 ||
				(ft_strlen(mapinfo->map[j + 1]) < (size_t)i + 1) ||
				(ft_strlen(mapinfo->map[j - 1]) < (size_t)i + 1) ||
				mapinfo->map[j - 1][i] == ' ' || mapinfo->map[j][i - 1] == ' '
				||mapinfo->map[j][i + 1] == ' ' ||
				mapinfo->map[j + 1][i] == ' ')
				error_free(mapinfo, NULL, "ERROR: This should be a one☝️");
		}
	}
	return ;
}

void	map_line_checker( t_mapinfo *mapinfo)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mapinfo->map[j++])
	{
		i = 0;
		while (mapinfo->map[j][i])
		{
			if (mapinfo->map[j][i] == '1' || mapinfo->map[j][i] == '0'
				|| mapinfo->map[j][i] == ' ' || mapinfo->map[j][i] == '\n')
				space_dealer(mapinfo, i, j);
			else if (mapinfo->map[j][i] == 'N' || mapinfo->map[j][i] == 'S'
					|| mapinfo->map[j][i] == 'E' || mapinfo->map[j][i] == 'W')
			{
				space_dealer(mapinfo, i, j);
				if (sto_finder(mapinfo->map[j][i], mapinfo) == 1)
					error_free(mapinfo, NULL, "ERROR: more then one player");
			}
			else
				error_free(mapinfo, NULL, "ERROR: not supposed to be there🐛");
			i++;
		}
	}
}

void	take_map( t_mapinfo *mapinfo)
{
	map_line_checker(mapinfo);
	max_line(mapinfo);
	initial_pos_player(mapinfo);
}
