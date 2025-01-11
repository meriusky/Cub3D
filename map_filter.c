/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:16:32 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/10 16:51:32 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
void	space_dealer(t_mapinfo *mapinfo, int i, int j)
{
	printf("char de space_dealer: %c\n", mapinfo->map[j][i]);
	if(mapinfo->map[j][i] != ' ' && mapinfo->map[j][i] != '\n')
	{
		printf("char dentro while: %c\n", mapinfo->map[j][i]);
		if(mapinfo->map[j][i] != '1')
		{
			if((j == 0 && mapinfo->map[j][i] != 1) || i == 0 || (ft_strlen(mapinfo->map[j+1])
			< (size_t)i+1) || (ft_strlen(mapinfo->map[j-1]) < (size_t)i+1) ||
			mapinfo->map[j-1][i] == ' ' || mapinfo->map[j][i-1] == ' ' || 
			mapinfo->map[j][i+1] == ' ' || mapinfo->map[j+1][i] == ' ')
			{
				printf("ERROR: This should be a one☝️\n");
				printf("j:%d\n", j);
				printf("i:%d\n", i);
				error_free(mapinfo, NULL);
			}
		}
	}
	return ;
}

int		map_line_checker( t_mapinfo *mapinfo)
{
	int i;
	int j;

	i = 0;
	j = 0;

	printf("🍋map_line_checker\n");
	while(mapinfo->map[j])
	{
		i = 0;
		while(mapinfo->map[j][i])
		{
			if(mapinfo->map[j][i] == '1' || mapinfo->map[j][i] == '0' 
				|| mapinfo->map[j][i] == ' ' || mapinfo->map[j][i] == '\n')
			{
				printf("map_char🍋: %c\n", mapinfo->map[j][i]);
				space_dealer(mapinfo, i, j);
			}
			else if(mapinfo->map[j][i] == 'N' || mapinfo->map[j][i] == 'S' 
					|| mapinfo->map[j][i] == 'E' || mapinfo->map[j][i] == 'W')
			{
				space_dealer(mapinfo, i, j);
				printf("🍋char encontrado: %c\n", mapinfo->map[j][i]);
				if(sto_finder(mapinfo->map[j][i], mapinfo) == 1)
					error_free(mapinfo, NULL);
			}
			else
			{
				printf("MAP ERROR: something is not supposed to be there🐛\n");
				error_free(mapinfo, NULL);
			}
			i++;
		}
		j++;
	}
	return(0);
}

void	take_map( t_mapinfo *mapinfo)
{

	printf("🍊take_map\n");
	if(map_line_checker(mapinfo) == 1)
		error_free(mapinfo, NULL);
	max_line(mapinfo);
	initial_pos_player(mapinfo);
	printf("🍊everything full👌\n");	
}
