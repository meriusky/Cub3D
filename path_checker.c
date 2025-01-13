/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:02:15 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/13 17:10:36 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

void	extension_checker(char *line)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (line[i] != '\n')
	{
		if (line[i] == '.' && line[i + 1] == 'p' && line[i + 2] == 'n'
			&& line[i + 3] == 'g' && line[i + 4] == '\n')
		{
			check++;
			printf("extension correct✅\n");
		}
		i++;
	}
	if (check != 1)
		error_free(NULL, line, "ERROR: wrong extension, just .png allawed📸");
	return ;
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
		error_free(NULL, line, "ERROR: Wrong path");
	else
	{
		close(check);
		extension_checker(line);
	}
}
