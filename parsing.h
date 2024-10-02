/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:23:56 by mehernan          #+#    #+#             */
/*   Updated: 2024/10/02 18:33:58 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_mapinfo
{
	char				*north;
	char				*south;
	char				*west;
	char				*east;
	char				*floor;
	char				*ceiling;
//	struct s_mapinfo	*next;
}	t_mapinfo;

void	sorter(char *line, t_mapinfo *mapinfo);

#endif

//en caso de error y que haya que liberar los mallocs
// va a dar segfault cuando inte liberar algo que no ha sido ocupado con informacion.
// Meter todo a zero con el bzero para que no de segfault y luego rellenar la lista.
//
