/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:00:00 by mehernan          #+#    #+#             */
/*   Updated: 2024/12/20 17:27:59 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_realloc(void *ptr, size_t new_size) 
{
	void	*new_ptr;

    if (ptr == NULL) 
        return ft_calloc(new_size, sizeof(char));
    if (new_size == 0)
   	{
        free(ptr);
        return NULL;
    }
    new_ptr = ft_calloc(new_size, sizeof(char));
    if (!new_ptr)
        return NULL;
    ft_memcpy(new_ptr, ptr, ft_strlen(ptr));
    free(ptr);
    return new_ptr;
}


