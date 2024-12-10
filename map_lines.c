//poner heather

#include "parsing.h"
void count_map_lines(t_mapinfo *mapinfo, char *line) 
{
	printf("🍎count_map_lines\n");
    static int j = 0;              // Guarda el numero de lineas del mapa
//la estatica se puede declarar asi.
	//ajusta el tamanyo de
    mapinfo->map = ft_realloc(mapinfo->map, (j + 2) * sizeof(char *));
    if (!mapinfo->map) 
	{
        printf("Failed to reallocate memory\n");
        error_free(mapinfo, line); // por si falla
    }
 // Guarda memoria para la linea y copia el contenido
	mapinfo->map[j] = ft_strdup(line);
	printf("🍎lo que metimos en mapinfo->map[j]: %s\n", mapinfo->map[j]);
    if (!mapinfo->map[j]) 
	{
        printf("Failed to allocate memory for line\n");
        error_free(mapinfo, line);
    }
    j++;
//    mapinfo->rows = j;// se podria poner mapinfo->max_y;
}

