/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:15:28 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/13 15:16:15 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	space_count(char *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (p[i] != '\0')
	{
		if (p[i] != ' ')
			j++;
		i++;
	}
	return (j);
}

char	*ft_remove_spaces(char *str)
{
	int		j;
	int		i;
	char	*p;
	char	*new_str;

	p = str;
	j = space_count(p);
	i = 0;
	if (!str)
		return (NULL);
	new_str = malloc(ft_strlen(str) - j);
	if (!new_str)
		exit(1);
	j = 0;
	while (p[i] != '\0')
	{
		if (p[i] != ' ')
		{
			new_str[j] = p[i];
			j++;
		}
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}
