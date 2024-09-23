/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:48:02 by mehernan          #+#    #+#             */
/*   Updated: 2024/09/19 11:35:28 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

// funcion para busca el /n //pero tiene que decir en que posicion esta o algo
char	*search_char(const char *s, char c)
{
	int	count;

	count = 0;
	while (s[count] != '\0' && (s[count] != (unsigned char)c))
		count++;
	if ((unsigned char)c == s[count])
		return ((char *)&s[count]);
	else if (c == '\0')
		return ((char *)&s[count]);
	return (NULL);
}
// la funcion que corta substr 
char	*cutstr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	count2;
	char	*result;

	count = 0;
	count2 = 0;
	while (s[count] != '\0')
		count++;
	if (start >= count)
		start = count;
	if (len > count - start)
		len = count - start;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (count2 < len)
	{
		result[count2] = s[start + count2];
		count2++;
	}
	result[count2] = '\0';
	free((void *)s);
	return (result);
}
//Hay que copiar la info del buffer a la statica.
char	*strjoin(char const *s1, char const *s2)
{
	char	*snew;
	size_t	count;
	size_t	size_s1;
	size_t	size_s2;

	count = -1;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	snew = (char *)malloc (sizeof(char) * (size_s1 + size_s2 + 1));
	if (snew == NULL)
		return (NULL);
	while (++count < size_s1)
		snew[count] = s1[count];
	count = 0;
	while (count <= size_s2)
	{
		count++;
		snew[size_s1 + count - 1] = s2[count - 1];
	}
	snew [size_s1 + count - 1] = '\0';
	free((void *)s1);
	return (snew);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
