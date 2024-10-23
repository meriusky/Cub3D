/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:22:48 by mehernan          #+#    #+#             */
/*   Updated: 2024/10/23 17:40:09 by mehernan         ###   ########.fr       */
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
//	int	len_line;

	if (argc == 2)
	{
		if (dot_cub_checker(argv) == 0)
			fd = open(argv[1], O_RDONLY);// Y para que lo abro?
		else
			exit(1);
		line = get_next_line(fd);
//		len_line = ft_strlen(line);
//		printf("%d\n", len_line);
//		line[len_line + 1] = '\0';
//esta parafernalia es porque como line no tiene valos hasta llegar al while 
//puede dar problemas con segfaults y eso		
		while (line != NULL)
		{
			printf("main: %s", line);
			sorter(line, &mapinfo);
			free(line);
			line = get_next_line(fd);// possible causante del error💀
									 // no entiendo como esta yendo a la siguiente line
									 // creo que deberia hacerse y no se esta haiendo
//			len_line = ft_strlen(line);
//			line[len_line + 1] = '\0';
		}
	}
	else
		printf("ERROR: just the executable and map name allowed\n");
	return (0);
}
// lo que tocaria ahora es ir leyendo el archivo y cada linea
// que se coge debe pasar un filtro. Miramos si en NO SO o lo
// que sea y la metemos donde corresconda de la lista.
// si se hace eso se debe tener en cuenta que como es una lista
// los otros nodos se van a quedar vacios y eso puede liar la troca.
// Veremos si se me ocurre alguna manera mejor de hacerlo y que este organizado.
//
//
//descubrir como lee las cosas y como puedo ir cogiendo 
// linea por linea, asi que me temo que este main quedara obsoleto.
//
// Tema leer el mapa 1 y 0:
// Esto no se puede hacer cogiendo string por string es de locos
// y muy largo. Lo mejor es con el floodfiles o algo asi, como con 
// el fractol. Es un tema que ya se hablo con Frank, pero vaya, hay
// que investigar mas.
