/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:22:48 by mehernan          #+#    #+#             */
/*   Updated: 2024/11/21 21:01:00 by mehernan         ###   ########.fr       */
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
		ft_bzero(&mapinfo, sizeof(t_mapinfo));// para inicializar
		line = get_next_line(fd);
		while (line != NULL)
		{
			printf("main: %s", line);
			sorter(line, &mapinfo);
			free(line);
			line = get_next_line(fd);// possible causante del error💀
									 //no entiendo como esta yendo a la siguiente
		}
		take_map(&mapinfo);
	}
	else
		printf("ERROR: just the executable and map name allowed\n");
	return (0);
}
//consultar subject bien si los colores pueden llevar espacios entre
//comas, deduzco que no
//descubrir como lee las cosas y como puedo ir cogiendo 
// linea por linea, asi que me temo que este main quedara obsoleto.
//QUE ESTA PASANDO AHORA:
//Estoy solucionando el problema que hay en fill_map, necesito saber cuantas
//filas hay en el mapa para poder hacer malloc, la cuestion es que count_map
//cuenta las filas con f ya que son variables estaticas. Yo queria pasarle a
// take_map la j, con el return de count_map pero no es possible ya que para
//  eso deberia saber cuando es la ultima linea de line. Eso es lo que estaba
//   haciendo ahora en el main. Queria poner una condicion rollo cuando 
//   line+1 = NUll, pero no puedo hacer eso porque estoy cogiendo cada linea 
//   con el get_next_line. Hay que ver como solucionarlo.
//
//TRUCO PARA ELIMINAR LINEAS💡
//Hagamos que en el error management, en la funcion error_free ponemos
//que pille string que sera lo que printeamos. Asi quitamos los {} y el
//printf de muchos errores;
