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
		//	printf("todo bien\n");
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
