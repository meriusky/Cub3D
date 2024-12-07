//poner heather

#include "parsing.h"
void count_map_lines(t_mapinfo *mapinfo, char *line) 
{
    static int j = 0;              // Guarda el numero de lineas del mapa

	//ajusta el tamanyo de
    mapinfo->map = ft_realloc(map_copy, (j + 2) * sizeof(char *));
    if (!mapinfo->map) 
	{
        printf("Failed to reallocate memory\n");
        error_free(mapinfo, line); // por si falla
    }
 // Guarda memoria para la linea y copia el contenido
	mapinfo->map[j] = ft_strdup(line);
    if (!mapinfo->map[j]) 
	{
        printf("Failed to allocate memory for line\n");
        error_free(mapinfo, line);
    }
    j++;
//    mapinfo->rows = j;// se podria poner mapinfo->max_y;
}

