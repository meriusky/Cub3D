/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:23:56 by mehernan          #+#    #+#             */
/*   Updated: 2024/09/30 20:14:04 by mehernan         ###   ########.fr       */
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
	struct s_mapinfo	*next;
}	t_mapinfo;
//quizas hay mejor manera de organizarlo
#endif
