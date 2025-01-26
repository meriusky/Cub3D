/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:04:21 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/26 15:26:41 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

void	error_args(void)
{
	ft_fd_printf(2, "ERROR: ARGS: Just the executable and map path\n");
	exit(1);
}

void	error_free(t_mapinfo *mapinfo, char *line, char *print)
{
	int	i;

	i = 0;
	ft_fd_printf(2, "%s\n", print);
	free(line);
	if (mapinfo != NULL)
	{
		free(mapinfo->north);
		free(mapinfo->south);
		free(mapinfo->west);
		free(mapinfo->east);
		free(mapinfo->raw_ceiling);
		free(mapinfo->raw_floor);
		while (i <= mapinfo->max_y)
		{
			if (mapinfo->map && mapinfo->map[i])
				free(mapinfo->map[i]);
			i++;
		}
		free(mapinfo->map);
	}
	exit(1);
}
