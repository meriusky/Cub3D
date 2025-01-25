/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:46:16 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/12 19:34:26 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

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
	while (line[++count] != '\0')
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
	while (++i < (count + check))
		newline[i] = line[i];
	newline[i] = '\0';
	return (newline);
}

char	*read_and_save(int fd, char *line)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	while (search_char(buffer, '\n') == NULL)
	{
		read_bytes = read (fd, buffer, BUFFER_SIZE);
		if (read_bytes == 0)
			break ;
		if (read_bytes == -1)
		{
			free (buffer);
			free(line);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		line = strjoin(line, buffer);
	}
	free (buffer);
	return (line);
}

char	*delete_line(char *line)
{
	int	count;
	int	start;

	count = 0;
	start = 0;
	if (!line)
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
	line = cutstr(line, start, (count - start));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
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
	line = delete_line(line);
	if (!line)
		free(line);
	return (newline);
}
