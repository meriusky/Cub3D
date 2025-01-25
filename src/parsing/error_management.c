/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:04:21 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/25 19:01:01 by frankgar         ###   ########.fr       */
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
		free(mapinfo->map);
	}
	exit(1);
}
