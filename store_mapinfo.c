/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_mapinfo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:23:26 by mehernan          #+#    #+#             */
/*   Updated: 2024/11/18 20:28:41 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
//crear funcion para que en caso de error libere todo o simplemente hacer free
//cuando toque, no se que me ahorraria mas lineas
void	north_texture(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O')
	{
		i = i + 2;
		printf("entro 1r if: %c\n", line[i]);
		while (line[i] != '\n')
		{
			printf("dentro while: %c\n", line[i]);
			if (line[i] == ' ' || line[i] == '	')
				i++;
			else if ((line[i] == '.' && line[i + 1] == '/') && line[i + 2] != '\0')
			{
				printf("dentro else if: %c\n", line[i]);
				if(mapinfo->north != NULL)
				{
					printf("ERROR: duplicated texture\n");
					//futura funcion de free de todo💡
					exit(1);
				}
				mapinfo->north = ft_calloc(ft_strlen(line), sizeof(char));
				mapinfo->north = line;
				// COMPROBAR PATH, buscarlo en google
				printf("✅:%s\n", line);
				return ;
			}
		}
		printf("error: wrong north texture path\n");
		exit(1);
	}
	else
	{
		printf("ERROR: north textute information wrong\n");
		exit(1);
	}
}

void	south_texture(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'S' && line[i + 1] == 'O')
	{
		i = i + 2;
		printf("entro 1r if: %c\n", line[i]);
		while (line[i] != '\n')
		{
			printf("dentro while: %c\n", line[i]);
			if (line[i] == ' ' || line[i] == '	')
				i++;
			else if ((line[i] == '.' && line[i + 1] == '/') && line[i + 2] != '\0')
			{
				printf("dentro else if: %c\n", line[i]);
				if(mapinfo->south != NULL)
				{
					printf("ERROR: duplicated texture\n");
					//futura funcion de free de todo💡
					exit(1);
				}
				mapinfo->south = ft_calloc(ft_strlen(line), sizeof(char));
				mapinfo->south = line;
				// COMPROBAR PATH, buscarlo en google
				printf("✅:%s\n", line);
				return ;
			}
		}
		printf("error: wrong south texture path\n");
		exit(1);
	}
	else
	{
		printf("ERROR: south textute information wrong\n");
		exit(1);
	}
}

void	west_texture(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'W' && line[i + 1] == 'E')
	{
		i = i + 2;
		printf("entro 1r if: %c\n", line[i]);
		while (line[i] != '\n')
		{
			printf("dentro while: %c\n", line[i]);
			if (line[i] == ' ' || line[i] == '	')
				i++;
			else if ((line[i] == '.' && line[i + 1] == '/') && line[i + 2] != '\0')
			{
				printf("dentro else if: %c\n", line[i]);
				if(mapinfo->west != NULL)
				{
					printf("ERROR: duplicated texture\n");
					//futura funcion de free de todo💡
					exit(1);
				}
				mapinfo->west = ft_calloc(ft_strlen(line), sizeof(char));
				mapinfo->west = line;
				// COMPROBAR PATH, buscarlo en google
				printf("✅:%s\n", line);
				return ;
			}
		}
		printf("error: wrong west texture path\n");
		exit(1);
	}
	else
	{
		printf("ERROR: west textute information wrong\n");
		exit(1);
	}
}

void	east_texture(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'E' && line[i + 1] == 'A')
	{
		i = i + 2;
		printf("entro 1r if: %c\n", line[i]);
		while (line[i] != '\n')
		{
			printf("dentro while: %c\n", line[i]);
			if (line[i] == ' ' || line[i] == '	')
				i++;
			else if ((line[i] == '.' && line[i + 1] == '/') && line[i + 2] != '\0')
			{
				printf("dentro else if: %c\n", line[i]);
				if(mapinfo->east != NULL)
				{
					printf("ERROR: duplicated texture\n");
					//futura funcion de free de todo💡
					exit(1);
				}
				mapinfo->east = ft_calloc(ft_strlen(line), sizeof(char));
				mapinfo->east = line;
				// COMPROBAR PATH, buscarlo en google
				printf("✅:%s\n", line);
				return ;
			}
		}
		printf("error: wrong east texture path\n");
		exit(1);
	}
	else
	{
		printf("ERROR: east textute information wrong\n");
		exit(1);
	}
}

