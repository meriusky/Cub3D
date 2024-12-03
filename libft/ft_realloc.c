//poner heather
#include "libft.h"

void *ft_realloc(void *ptr, size_t new_size) 
{
    if (ptr == NULL) 
        return malloc(new_size);
    if (new_size == 0)
   	{
        free(ptr);
        return NULL;
    }
    void *new_ptr = malloc(new_size);
    if (!new_ptr)
        return NULL;
    ft_memcpy(new_ptr, ptr, new_size); 
    free(ptr);
    return new_ptr;
}

