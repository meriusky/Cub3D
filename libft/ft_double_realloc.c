/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_realloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:26:47 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/12 19:16:55 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	**ft_double_realloc(char **ptr, size_t new_size)
{
	char	**new_ptr;
	size_t	old_size;
	size_t	size_to_copy;

	if (ptr == NULL)
		return (calloc(new_size, sizeof(char *)));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = calloc(new_size, sizeof(char *));
	if (!new_ptr)
		return (NULL);
	old_size = 0;
	while (ptr[old_size] != NULL)
		old_size++;
	if (old_size < new_size)
		size_to_copy = old_size;
	else
		size_to_copy = new_size;
	ft_memcpy(new_ptr, ptr, size_to_copy * sizeof(char *));
	free(ptr);
	return (new_ptr);
}
