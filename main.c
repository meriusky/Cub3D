/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:22:48 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/13 17:06:37 by mehernan         ###   ########.fr       */
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
			printf("ERROR: just files .cub allowed\n");
			return (1);
		}
	}
	else
	{
		printf("ERROR: file not valid\n");
		return (1);
	}
}

int	open_error(char *argv, int fd)
{
	fd = open(argv, O_RDONLY);
	if(fd == -1)
	{
		printf("ERROR: file doesn't exist\n");
		exit(1);
	}
	return (fd);
}

int	main(int argc, char **argv)
{
	int			fd;
	char		*line;
	t_mapinfo	mapinfo;

	fd = 0;
	if (argc == 2)
	{
		if (dot_cub_checker(argv) == 0)
			fd = open_error(argv[1], fd);
		else
			exit(1);
		ft_bzero(&mapinfo, sizeof(t_mapinfo));
		line = get_next_line(fd);
		while (line != NULL)
		{
			sorter(line, &mapinfo);
			free(line);
			line = get_next_line(fd);
		}
		take_map(&mapinfo);
	}
	else
		printf("ERROR: just the executable and map name allowed\n");
	close(fd);
	return (0);
}
/*
int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_mapinfo mapinfo;

	if (argc == 2)
	{
		if (dot_cub_checker(argv) == 0)
		{
			fd = open(argv[1], O_RDONLY);
			if(fd == -1)
			{
				printf("ERROR: file doesn't exist\n");
				exit(1);
			}
		}
		else
			exit(1);
		ft_bzero(&mapinfo, sizeof(t_mapinfo));
		line = get_next_line(fd);
		while (line != NULL)
		{
			printf("main: %s", line);
			sorter(line, &mapinfo);
			free(line);
			line = get_next_line(fd);
		}
		take_map(&mapinfo);
	}
	else
		printf("ERROR: just the executable and map name allowed\n");
	return (0);
}*/
//TRUCO PARA ELIMINAR LINEAS💡
//Hagamos que en el error management, en la funcion error_free ponemos
//que pille string que sera lo que printeamos. Asi quitamos los {} y el
//printf de muchos errores;
