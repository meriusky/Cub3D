#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

// funcion para comprobar que el archivo no sea un trolleo,
// es decir, que sea algo.cub y no cosas rarars, esta en proceso
void	map_name_rules(char **argv)
{
	int name_len;
	name_len = strlen(argv[1]);

	if(name_len >= 5)
	{
			if(argv[1][name_len] == 'b'||argv[1][name_len - 1] == 'u'|| argv[1][name_len] == 'b'||
	}
	else
	{
		printf("ERROR: file not valid\n");
		exit(1);
	}



}
int main(int argc, char **argv)
{
	int fd;
	char *line;

	if(argc == 2)
	{
		map_name_rules(argv);
		fd = open("test.txt", O_RDONLY);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	else
			printf("ERROR: just the executable and map name allowed\n");
//	printf("\n");
//	line = get_next_line(fd);
//	printf("%s", line);
//	free(line);
//	line = get_next_line(fd);
//	printf("%s", line);
//	free(line);
//	line = get_next_line(fd);
//	printf("%s", line);
//	free(line);
//	line = get_next_line(fd);
//	printf("%s", line);
	return(0);
}
