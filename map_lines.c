//poner heather

#include "parsing.h"
void	count_map(char *line)
{
	static char **map_copy;
	int	i;
	static int	j;
	
	i = 0;
	j = 0;
	map_copy = calloc(j + 1, sizeof(char *));
	map_copy[j] = strcpy(map_copy, line);//strcpy hay que hacerlo
//	while(map_copy[j][i])
//	{
//		map_copy[j][i] = line[i];
//		i++;
//	}
	j++;
}
