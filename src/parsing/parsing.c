/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:22:48 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/25 20:18:48 by frankgar         ###   ########.fr       */
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
		{
			ft_fd_printf(2, "ERROR: just files .cub allowed\n");
			return (1);
		}
	}
	else
	{
		ft_fd_printf(2, "ERROR: file not valid\n");
		return (1);
	}
}

int	open_error(char *argv, int fd)
{
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_fd_printf(2, "ERROR: file doesn't exist\n");
		exit(1);
	}
	return (fd);
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
		else
			exit(1);
		line = get_next_line(fd);
		while (line != NULL)
		{
			sorter(line, &mapinfo);
			free(line);
			line = get_next_line(fd);
		}
		take_map(&mapinfo);
		close(fd);
	}
	else
		error_args();
	return (mapinfo);
}
