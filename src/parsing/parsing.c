/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:22:48 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/26 17:23:46 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

int	dot_cub_checker(char **argv)
{
	int	name_len;

	name_len = ft_strlen(argv[1]);
	if (name_len >= 5)
	{
		if (argv[1][name_len - 1] == 'b' && argv[1][name_len - 2] == 'u' &&
				argv[1][name_len - 3] == 'c' && argv[1][name_len - 4] == '.')
			return (0);
		else
			error_free(NULL, NULL, "ERROR: Just files .cub allowed");
	}
	else
		error_free(NULL, NULL, "ERROR: File not valid");
	return (0);
}

int	open_error(char *argv, int fd)
{
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		error_free(NULL, NULL, "ERROR: File doesn't exist");
	return (fd);
}

void	check_content(t_mapinfo mapinfo)
{
	if (!(mapinfo.map && *mapinfo.map && **mapinfo.map && \
		mapinfo.north && mapinfo.south && mapinfo.east && mapinfo.south && \
		mapinfo.stx && mapinfo.sty))
		error_free(NULL, NULL, "ERROR: Missing content\n");
}

t_mapinfo	parsing(int argc, char **argv)
{
	int			fd;
	char		*line;
	t_mapinfo	mapinfo;

	fd = 0;
	ft_bzero(&mapinfo, sizeof(t_mapinfo));
	if (argc == 2)
	{
		if (dot_cub_checker(argv) == 0)
			fd = open_error(argv[1], fd);
		line = get_next_line(fd);
		while (line != NULL)
		{
			sorter(line, &mapinfo);
			free(line);
			line = get_next_line(fd);
		}
		take_map(&mapinfo);
		close(fd);
		check_content(mapinfo);
	}
	else
		error_args();
	return (mapinfo);
}
