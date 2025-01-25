/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:02:15 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/25 21:05:49 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

void	extension_checker(char *line)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '.' && line[i + 1] == 'p' && line[i + 2] == 'n'
			&& line[i + 3] == 'g' && line[i + 4] == '\0')
			check++;
		i++;
	}
	if (check != 1)
		error_free(NULL, line, "ERROR: wrong extension, just .png allawed📸");
	return ;
}

char	*get_texture_path(char *line)
{
	int	i;
	int	end_line;

	i = 2;
	while (line[i] && line[i] == ' ')
		i++;
	end_line = i;
	while (line[end_line])
		end_line++;
	if (line[end_line - 1] == '\n')
		line[end_line - 1] = '\0';
	return (&line[i]);
}

void	path_checker(char *line)
{
	int		i;
	int		check;
	char	*path;

	i = 0;
	while (line[i] != '.')
		i++;
	path = ft_substr(line, i, ft_strlen(line) - i);
	check = open(path, O_RDONLY);
	if (check < 0)
		error_free(NULL, path, "ERROR: Wrong path");
	else
	{
		close(check);
		extension_checker(line);
		free(path);
	}
}
