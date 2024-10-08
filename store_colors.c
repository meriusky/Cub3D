/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:25:28 by mehernan          #+#    #+#             */
/*   Updated: 2024/10/08 18:02:31 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

void	floor_color(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'F')
	{
		while (line[i] != '\n')
		{
			if (line[i] == ' ' || line[i] == '	')
				i++;
			if (line[i] >= '0' && line[i] <= '9')
			{
				rgb_checker(line, i);
				mapinfo->floor = line;
				printf("%s\n", line);
//				return (0);
			}
		}
	}
	else
	{
		printf("ERROR: floor color information wrong\n");
//		return (1);
		exit(1);
	}
}

void	ceiling_color(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'C')
{
		while (line[i] != '\n')
		{
			if (line[i] == ' ' || line[i] == '	')
				i++;
			if (line[i] >= '0' && line[i] <= '9')
			{
				rgb_checker(line, i);
				mapinfo->floor = line;
				printf("%s\n", line);
//				return (0);
			}
		}
	}
	else
	{
		printf("ERROR: floor color information wrong\n");
//		return (1);
		exit(1);
	}
}

