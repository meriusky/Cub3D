#include "parsing.h"

int	map_name_rules(char **argv)
{
	int name_len;
	name_len = ft_strlen(argv[1]);

	if(name_len >= 5)
	{
			if(argv[1][name_len - 1] == 'b'&& argv[1][name_len - 2] == 'u'&& 
							argv[1][name_len - 3] == 'c' && argv[1][name_len - 4] == '.')
				return(0);
			else
			{
					printf("ERROR: just files .cub allowed\n");
					return(1);
			}

	}
	else
	{
		printf("ERROR: file not valid\n");
		return(1);
	}
}

int main(int argc, char **argv)
{
	int fd;
	char *line;

	if(argc == 2)
	{
		if(map_name_rules(argv) == 0)
			fd = open(argv[1], O_RDONLY);
		else
				exit(1);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	else
			printf("ERROR: just the executable and map name allowed\n");
	return(0);
}

// no funciona y me temo que es porque en el open esta cogiendo
// el nombre pero no el arhcivo, ya que el get_next_line da null. 
// Lo bueno es que lo filtros funcionan y si no es .cub no lo coge. 
// Despues de corregir eso y que printee con el get_next_line las 
// cosas hayq ue descumbrir como lee las cosas y como puedo ir cogiendo 
// linea por linea, asi que me temo que este main quedara obsoleto.
