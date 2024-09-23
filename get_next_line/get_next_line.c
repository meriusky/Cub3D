/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:46:16 by mehernan          #+#    #+#             */
/*   Updated: 2024/09/23 13:04:28 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

//funcio que te devuelve la linea que vas a printear
char	*show_newline(char *line)
{
	int		i;
	int		count;
	int		check;
	char	*newline;

	i = -1;
	count = -1;
	check = 0;
	if (!line || line[0] == '\0')
		return (NULL);
	while (line[++count] != '\0')// while solo para el malloc, hay que gurdar cuantos char va a haber, pereza :(
	{
		if (line[count] == '\n')
		{
			check += 1;
			break ;
		}
	}
	newline = malloc(sizeof(char) * (count + check + 1));
	if (!newline)
		return (NULL);
	while (++i < (count + check))// que pasa si no hay un \n, no debe hace nada.
		newline[i] = line[i];
	newline[i] = '\0';
	return (newline);
}
// Una funcion que lea y guarde la info (con una estatica) y que este el buffer tambien (delimitar lineas)
char	*read_and_save(int fd, char *line)
{
	char	*buffer;
	int		read_bytes; //esta variable sirve para guardar el nº de bytes y cosicas

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0'; // si no ponems esto da segmentation fault
	while (search_char(buffer, '\n') == NULL)
	{
		read_bytes = read (fd, buffer, BUFFER_SIZE); // el archivo, la variable (que almacena el texto), el tamano
		if (read_bytes == 0)
			break ;
		if (read_bytes == -1)
		{
			free (buffer);//si hay un error, ahi hay memoria que no se usara y debe ser liberada
			free(line);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		line = strjoin(line, buffer);
	}
	free (buffer);
	return (line);
}
// Otra funcion que te limpie la estatica de la linea que acabas de mostrar y devuela la statca sin la linea
char	*delete_line(char *line)
{
	int	count;
	int	start;

	count = 0;
	start = 0;
	if (!line) //si la statica esta vacia
		return (NULL);
	while (line[count] != '\0')
	{
		if (line[count] == '\n' && start == 0)
			start = count + 1;
		count++;
	}
	if (!start)
	{
		free(line);
		return (NULL);
	}
	line = cutstr(line, start, (count - start));// start es dodne cortas y la longitud es desde el punto donde ha encontrado \n mas uno porque queremos que lo pase
	//aqui hay que hacer que lo elmine
	return (line);
}
// El get next line lo puedo usar para llamar a otras funciones y puede que para printear las frases pero bueno, esta por ver
char *get_next_line(int fd)
{
	static char	*line = NULL;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0) //si el fd es incorrecto o el Buffer es menor de 0
		return (NULL);
	if (!line)
	{
		line = (char *)malloc(sizeof(char) * 1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	line = read_and_save(fd, line);
	newline = show_newline(line);
	if (!newline)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	line = delete_line(line);// con las staticas hay que "="asignar el nuevo valor  cuando las mandas a otra funcion
	if (!line)
		free(line);
	return (newline);
}
