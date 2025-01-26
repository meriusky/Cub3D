/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:01:18 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/26 14:18:33 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	max_line(t_mapinfo *mapinfo)
{
	size_t	max_row;
	int		j;

	max_row = 0;
	j = 0;
	while (mapinfo->map && mapinfo->map[j])
	{
		if (max_row < ft_strlen(mapinfo->map[j]))
			max_row = ft_strlen(mapinfo->map[j]);
		j++;
	}
	mapinfo->max_x = max_row;
}

int	sto_finder(char c, t_mapinfo *mapinfo)
{
	static int	check = 0;

	if (check == 0)
	{
		if (c == 'N')
			mapinfo->sto = 90;
		else if (c == 'S')
			mapinfo->sto = 270;
		else if (c == 'E')
			mapinfo->sto = 0;
		else if (c == 'W')
			mapinfo->sto = 180;
		check++;
		return (0);
	}
	else
		return (1);
}

void	initial_pos_player( t_mapinfo *mapinfo)
{
	int	i;
	int	j;

	j = 0;
	while (mapinfo->map && mapinfo->map[j])
	{
		i = 0;
		while (mapinfo->map[j][i])
		{
			if (mapinfo->map[j][i] != '1' && mapinfo->map[j][i] != '0'
				&& mapinfo->map[j][i] != ' ' && mapinfo->map[j][i] != '\n')
			{
				mapinfo->sty = j;
				mapinfo->stx = i;
				return ;
			}
			i++;
		}
		j++;
	}
}
