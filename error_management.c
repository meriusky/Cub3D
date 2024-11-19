// poner cartel
#include "parsing.h"
void	error_free(t_mapinfo *mapinfo, char *line)
{
//	printf("entro en error_free\n");
	free(line);
//	printf("line liberada\n");
	free(mapinfo->north);
//	printf("free de north\n");
	free(mapinfo->south);
//	printf("free de soutn\n");
	free(mapinfo->west);
//	printf("free de west\n");
	free(mapinfo->east);
//	printf("free de east\n");
	free(mapinfo->ceiling);
//	printf("free de ceiling\n");
	free(mapinfo->floor);
//	printf("free de floor\n");
	printf("todo liberado\n");
	exit(1);
}
