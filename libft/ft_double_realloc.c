/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_realloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:26:47 by mehernan          #+#    #+#             */
/*   Updated: 2024/12/20 17:59:04 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
void **ft_double_realloc(void **ptr, size_t new_size)
{
	void **new_ptr;
	size_t old_size; //numero de elementos en la array original
	size_t size_to_copy;//el mas pequenyo de los dos size, para no sobrepasar el maximo
	
	if(ptr == NULL)// si no existe el punterto se comporta como un malloc
		return calloc(new_size, sizeof(void *));
	if(new_size == 0)// si el new size es 0, free porque no hay nada
	{
		free(ptr);
		return NULL;
	}
	new_ptr = calloc(new_size, sizeof(void *));
	if(!new_ptr)
		return NULL;
	old_size = 0;//copiando el puntero ya existente en el nuevo
	while(ptr[old_size] != NULL)// contando los ya existentes
		old_size++;
	if(old_size < new_size)
		size_to_copy = old_size;
	else
		size_to_copy = new_size;
	ft_memcopy(new_ptr, ptr, size_to_copy * sizeof(void *));
	free(ptr);//Liberamos el antiguo
	return new_ptr;
}
