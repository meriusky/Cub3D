/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:47:25 by frankgar          #+#    #+#             */
/*   Updated: 2023/10/07 18:36:55 by frankgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize < dst_len)
		src_len += dstsize;
	else
		src_len += dst_len;
	while (src[i] && dst_len < dstsize - 1 && i < dstsize)
		dst[dst_len++] = src[i++];
	dst[dst_len] = '\0';
	return (src_len);
}
/*
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define COLOR_BLUE "\x1B[34m"
#define COLOR_GREEN "\x1B[32m"
#define COLOR_RESET "\x1B[0m"
#define COLOR_CYAN "\x1B[36m"
#define COLOR_MAGENTA "\x1B[35m"
#define COLOR_YELLOW "\x1B[33m"
#define COLOR_RED "\x1B[31m"
int nbsi(char *c)
{
	int i = 0;
	while (c[i] != '\0')
	{
		if (isdigit(c[i]))
			i++;
		else
			return(0);
	}
	return (1);
}
int main() 
{
	char a[50], b[50], c[30];
	size_t result;
	printf (COLOR_CYAN"Dst: "COLOR_RESET);
	scanf ("%[^\n]s", a);
	printf (COLOR_CYAN"Src: "COLOR_RESET);
	scanf ("%*c%[^\n]s", b);
	printf (COLOR_CYAN"Size: "COLOR_RESET);
	scanf ("%*c%s", c);
	while (nbsi(c) == 0)
	{
		printf (COLOR_RED"Comando no valido, Size tiene que ser un numero\n");
		printf (COLOR_CYAN"Size: "COLOR_RESET);
		scanf ("%s", c);
	}
	char *a2 = strdup ((const char *)a), *b2 = strdup ((const char *)b),
		*c2 = strdup ((const char *)c);

	//ORIGINAL
	printf (COLOR_MAGENTA"-------------------------------------------------\n");
	printf ("              FUNCION ORIGINAL strlcat:\n");
	printf ("Tu dst era: '%s'\n", a);
	result = strlcat( a, b, atoi(c));
	printf("Size de src es: '%zu', Tu dst tendria que dar: '%s' \n",
		   	result, a); 
	printf ("-------------------------------------------------\n");

	//PROPIA
	printf (COLOR_GREEN"-------------------------------------------------\n");
	printf ("              FUNCION PROPIA strlcat:\n");
	printf ("Tu dst era: '%s'\n", a2);
	result = ft_strlcat( a2, b2, atoi(c2));
	printf("Size de src es: '%zu', Tu dst da: '%s' \n",
			 result, a2);
	printf ("-------------------------------------------------\n");
	free (a2);
	free (b2);
	free (c2);

return (0);
}*/
