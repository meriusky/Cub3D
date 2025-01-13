/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:54:46 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/13 17:27:22 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	rgb_space(char *line, int i)
{
	int	check;
	int	space;

	check = 0;
	space = 0;
	while (line[i] != '\n')
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			if (space != 0)
				error_free(NULL, line, "ERROR: space between numbers");
			check++;
		}
		else if (check != 0 && line[i] == ' ')
			space++;
		else if (line[i] == ',' || line[i] == '\n')
		{
			space = 0;
			check = 0;
		}
		i++;
	}
	return ;
}

void	convert_rgb(t_mapinfo *mapinfo, int rgb, int check, char c)
{
	if (check == 1)
	{
		if (c == 'F')
			mapinfo->floor.r = rgb;
		else
			mapinfo->ceiling.r = rgb;
	}
	else if (check == 2)
	{
		if (c == 'F')
			mapinfo->floor.g = rgb;
		else
			mapinfo->ceiling.g = rgb;
	}
	else
	{
		if (c == 'F')
			mapinfo->floor.b = rgb;
		else
			mapinfo->ceiling.b = rgb;
	}
	return ;
}

int parse_color_component(char *line, int *index, t_mapinfo *mapinfo) 
{
    char str[4];
    int j;
	int rgb;
   
	j= 0;
    while (line[*index] >= '0' && line[*index] <= '9') 
	{
        if (j == 3)
            error_free(mapinfo, line, "ERROR: color with more than 3 digits");
        str[j++] = line[(*index)++];
    }
    str[j] = '\0';
    rgb = ft_atoi(str);
    if (rgb < 0 || rgb > 255)
        error_free(mapinfo, line, "ERROR: RGB color out of range");
    return rgb;
}

int rgb_checker(char *line, int i, t_mapinfo *mapinfo, char c)
{
    int check = 0;
    int rgb;

    while (line[i] != '\0')
	{
        if (line[i] == ' ') 
		{
            i++;
            continue;
        }
        rgb = parse_color_component(line, &i, mapinfo);
        check++;
        convert_rgb(mapinfo, rgb, check, c);
        if (line[i] == ',' || line[i] == '\n') 
            i++;
		else
		{
			printf("carcter:%c\n", line[i]);
            error_free(mapinfo, line, "ERROR: unexpected character in RGB");
		}
    }
    if (check == 3)
        return 0;
    error_free(mapinfo, line, "ERROR: three color components are required");
    return 1;
}
/*
int	rgb_checker(char *line, int i, t_mapinfo *mapinfo, char c)
{
	char	str[4];
	int		check;
	int		j;
	int		rgb;

	j = 0;
	check = 0;
	while (line[i] != '\0')
	{
		while (line[i] >= '0' && line[i] <= '9')
		{
			if (j == 3)
				error_free(mapinfo, line, "ERROR: color with more dan 3 digits");
			str[j] = line[i];
			i++;
			j++;
		}
		if ((line[i] == ',' || line[i] == '\n') && (j >= 1 && j <= 3))
		{
			str[j] = '\0';
			rgb = ft_atoi(str);
			if (rgb >= 0 && rgb <= 255)
			{
				str[0] = '\0';
				check++;
				convert_rgb(mapinfo, rgb, check, c);
				rgb = 0;
				j = 0;
				i++;
			}
			else
				error_free(mapinfo, line, "ERROR: rgb color wrong");
		}
		else if (line[i] == ' ')
			i++;
		else
			error_free(mapinfo, line, "ERROR: only RGB colors allowed\n");
	}
	if (check == 3)
		return (0);
	printf("ERROR: three colors are needed\n");
	return (1);
}*/
