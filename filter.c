/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:09:04 by mehernan          #+#    #+#             */
/*   Updated: 2024/10/02 18:36:51 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"
int	north_texture(char *line, t_mapinfo *mapinfo)
{
	int i;
	
	i = 0;
	while(line[i] != '\n')
	{
//		if(line[i-1] == 'O')
//		{
//			while(line[i] != '\0')
//			{
				if(line[i] == ' ' || line[i] == '	')
					i++;
				else if((line[i] == '.' && line[i+1] == '/') && line[i+2] != '\0')
				{
					mapinfo->north = line;
					printf("%s\n", line);
				}
				else
				{
					printf("error: wrong north texture path\n");
					exit(1);
//				}
//			}
			i++;
		}
	}
	return(1);
}
void	sorter(char *line, t_mapinfo *mapinfo)
{
	int i;
	int check;

	check = 6;
	i = 0;
	printf("🚨entra a sorter\n");
	while(line[i])
	{
		if(check == 0)
		{
			printf("error: too many textures or colors\n");
			exit(1);
		}
		if(line[i] == ' ')
			i++;
//		if((line[i] == 'N' && line[i+1] == 'O') || (line[i] == 'S' && line[i+1] == 'O') 
//			check = check - texture(line);
//			texture(line);
		if(line[i] == 'N' && line[i+1] == 'O')
				check = check - (north_texture(line, mapinfo));
	}
}
