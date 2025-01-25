/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_mapinfo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:23:26 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/25 20:38:55 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	north_texture(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O')
	{
		i = i + 2;
		while (line[i] != '\n')
		{
			if (line[i] == ' ' || line[i] == '	')
				i++;
			else if ((line[i] == '.' && line[i + 1] == '/')
				&& line[i + 2] != '\0')
			{
				if (mapinfo->north != NULL)
					error_free(mapinfo, line, "ERROR: duplicated texture");
				path_checker(get_texture_path(line));
				mapinfo->north = ft_strdup(get_texture_path(line));
				return ;
			}
		}
		error_free(mapinfo, line, "ERROR: wrong north texture path");
	}
	else
		error_free(mapinfo, line, "ERROR: north textute information wrong");
}

void	south_texture(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'S' && line[i + 1] == 'O')
	{
		i = i + 2;
		while (line[i] != '\n')
		{
			if (line[i] == ' ' || line[i] == '	')
				i++;
			else if ((line[i] == '.' && line[i + 1] == '/')
				&& line[i + 2] != '\0')
			{
				if (mapinfo->south != NULL)
					error_free(mapinfo, line, "ERROR: duplicated texture");
				path_checker(get_texture_path(line));
				mapinfo->south = ft_strdup(get_texture_path(line));
				return ;
			}
		}
		error_free(mapinfo, line, "error: wrong south texture path");
	}
	else
		error_free(mapinfo, line, "ERROR: south textute information wrong");
}

void	west_texture(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'W' && line[i + 1] == 'E')
	{
		i = i + 2;
		while (line[i] != '\n')
		{
			if (line[i] == ' ' || line[i] == '	')
				i++;
			else if ((line[i] == '.' && line[i + 1] == '/')
				&& line[i + 2] != '\0')
			{
				if (mapinfo->west != NULL)
					error_free(mapinfo, line, "ERROR: duplicated texture");
				path_checker(get_texture_path(line));
				mapinfo->west = ft_strdup(get_texture_path(line));
				return ;
			}
		}
		error_free(mapinfo, line, "error: wrong west texture path");
	}
	else
		error_free(mapinfo, line, "ERROR: west textute information wrong");
}

void	east_texture(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'E' && line[i + 1] == 'A')
	{
		i = i + 2;
		while (line[i] != '\n')
		{
			if (line[i] == ' ' || line[i] == '	')
				i++;
			else if ((line[i] == '.' && line[i + 1] == '/')
				&& line[i + 2] != '\0')
			{
				if (mapinfo->east != NULL)
					error_free(mapinfo, line, "ERROR: duplicated texture");
				path_checker(get_texture_path(line));
				mapinfo->east = ft_strdup(get_texture_path(line));
				return ;
			}
		}
		error_free(mapinfo, line, "error: wrong east texture path");
	}
	else
		error_free(mapinfo, line, "ERROR: east textute information wrong");
}
