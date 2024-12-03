//poner heather

#include "parsing.h"
void count_map(t_mapinfo *mapinfo, char *line) 
{
    static char **map_copy; //retiene el valor
    static int j;              // Guarda el numero de lineas del mapa
    char **temp;

	map_copy = NULL;
	j = 0;
	//ajusta el tamanyo de
    temp = realloc(map_copy, (j + 1) * sizeof(char *));
    if (!temp) 
	{
        printf("Failed to reallocate memory\n");
        error_free(mapinfo, line); // por si falla
    }
    map_copy = temp;
 // Guarda memoria para la linea y copia el contenido
    map_copy[j] = malloc(strlen(line) + 1); // +1 para que termine en null
    if (!map_copy[j]) 
	{
        printf("Failed to allocate memory for line\n");
        error_free(mapinfo, line);
    }
    strcpy(map_copy[j], line); // Copia la linea en  map_copy[j]
	mapinfo->map[j] = map_copy[j]; // Actualiza la informacion del mapa
    j++;
    mapinfo->rows = j;
}

