/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:25:28 by mehernan          #+#    #+#             */
/*   Updated: 2024/10/23 17:33:57 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

void	floor_color(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'F')
	{
		printf("📔%s\n", line);
		i++;
		while (line[i] != '\0')
		{
			if (line[i] == 32)
			{
				printf("📔espacio💫\n");
				i++;
			}
			if (line[i] >= 48 && line[i] <= 57)
			{
				printf("📔antes de entrar rgb checker\n");
				if(rgb_checker(line, i) == 0)
				{
					mapinfo->floor = line;//saber si hay que meterlo aqui.
				// hay que revisar que lleva la linea y que estamos metiendo⚠️
					printf("FIN: %s\n", line);
					return ;
				}
			}
			else
			{
					printf("📔ERROR: unexpected char not allowed\n");
					exit(1);
			}
		}
	}
	else
	{
		printf("📔ERROR: floor color information wrong\n");
		exit(1);
	}
}

void	ceiling_color(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'C')
{
		printf("📔%s\n", line);
		i++;
		while (line[i] != '\0')
		{
			if (line[i] == 32)
			{
				printf("📔espacio💫\n");
				i++;
			}
			if (line[i] >= 48 && line[i] <= 57)
			{
				printf("📔antes de entrar rgb checker\n");
				if(rgb_checker(line, i) == 0)
					mapinfo->ceiling = line;//saber si hay que meterlo aqui.
				// hay que revisar que lleva la linea y que estamos metiendo⚠️
				printf("%s\n", line);
			}
			else
			{
					printf("📔ERROR: unexpected char not allowed\n");
					exit(1);
			}
		}
	}
	else
	{
		printf("📔ERROR: ceiling color information wrong\n");
		exit(1);
	}
}
