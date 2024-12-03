//poner heather

#include "parsing.h"
void	count_map(t_mapinfo *mapinfo, char *line)
{
	static char **map_copy;
	int	i;
	static int	j;
	
	i = 0;
	j = 0;
	map_copy = calloc(j + 1, sizeof(char *));// usar realoc, crearlo en libft
	map_copy[j] = ft_strcpy(map_copy, line);
	j++;
	mapinfo->rows = j;
}
