/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_rgb_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:02:15 by mehernan          #+#    #+#             */
/*   Updated: 2025/01/10 18:41:22 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"
void	extension_checker(char *line)
{
	int i;
	int check;

	i = 0;
	check = 0;
	while(line[i] != '\n')
	{
		if(line[i] == '.' && line[i+1] == 'p' && line[i+2] == 'n'
			&& line[i+3] == 'g' && line[i+4] == '\n')
		{
			check++;
			printf("extension correct✅\n");
		}
		i++;
	}
	if(check != 1)
	{
		printf("ERROR: wrong extension, just .png allawed📸\n");
		error_free(NULL, line);
	}
	return ;
}

void	path_checker(/*t_mapinfo *mapinfo,*/ char *line)
{
	int i;
	int check;
	char *path;

	i = 0;
	while(line[i] != '.')
		i++;
	path = ft_substr(line, i, ft_strlen(line) - i);
	printf("path siendo revisado🗺️: %s\n", path);
	check = open(path, O_RDONLY);
	if(check < 0)
	{
		printf("ERROR: Wrong path\n");
		error_free(NULL, line);
	}
	else
	{
		close(check);
		extension_checker(line);
		printf("path is correct✅: %s\n", path);
	}

}

int	rgb_checker(char *line, int i)
{
	char str[4];
	int check;
	int j;
	int rgb;

	j = 0;
	check = 0;
	while(line[i] != '\n')
	{
		while(line[i] >= '0' && line[i] <= '9')
		{
			if(j == 3)
			{
				printf("ERROR: color with more dan 3 digits\n");
				exit(1);
			}
			str[j] = line[i];
			i++;
			j++;
		}
		if((line[i] == ',' || line[i] == '\n') && (j >= 1 && j <= 3))
		{
			str[j] = '\0';
			rgb = ft_atoi(str);
			if((rgb >= 0 && rgb <= 255) && check != 3)
			{
				str[0] = '\0';
				rgb = 0;
				j = 0;
				i++;
				check++;
				if(check == 3)
				{
					printf("✅COLOR CORRECT✅\n");
					return (0);
				}
			}
			else
			{
				printf("ERROR: rgb color wrong\n");
				exit(1);
			}
		}
		else
		{
			printf("ERROR: only RGB colors allowed\n");
			exit(1);
		}
	}
	if(check != 3)
	{
		printf("ERROR: three colors are needed\n");
		exit(1);
	}
	return(1);
}

