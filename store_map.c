/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:01:18 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/10 16:51:53 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
void	max_line(t_mapinfo *mapinfo)
{
	printf("🫑max_line\n");
	size_t max_row; // esto era un int pero lo cambie para que encajara con el ft_strlen
	int j;
	max_row = 0;
	j = 0;
	while(mapinfo->map[j])
	{
		if(max_row < ft_strlen(mapinfo->map[j]))
			max_row = ft_strlen(mapinfo->map[j]);
		j++;
	}
	mapinfo->max_y = j;
	mapinfo->max_x = max_row;
	printf("🫑max_x saved: %d\n", mapinfo->max_x);
	printf("🫑max_y saved: %d\n", mapinfo->max_y);
}

int	sto_finder(char c, t_mapinfo *mapinfo)
{
	static int check = 0;

	printf("🍐sto_finder\n");
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
		printf("🍐sto saved: %d\n", mapinfo->sto);
		check++;
		return(0);
	}
	else
	{
		printf("MAP ERROR: more that one player found🤼‍♀️\n");
		return(1);
	}
}

void	initial_pos_player( t_mapinfo *mapinfo)
{
	printf("🪼initial_pos_player\n");
	int i;
	int j;

	j = 0;
	while(mapinfo->map[j])
	{
		i = 0;
		while(mapinfo->map[j][i])
		{
//este if podria ser lo mismo que ponendo las letras, pero como hay muchos checkeos
//que comprueban que no se haya colado nada, lo pongo mas corto con 1 0 y sp
			if(mapinfo->map[j][i] != '1' && mapinfo->map[j][i] != '0' 
				&& mapinfo->map[j][i] != ' ' && mapinfo->map[j][i] != '\n')
			{
				mapinfo->sty = j;
				printf("🪼sty saved: %d\n", mapinfo->sty);
				mapinfo->stx = i;
				printf("🪼stx saved: %d\n", mapinfo->stx);	
				return ;
			}
			i++;
		}
		j++;
	}
}
