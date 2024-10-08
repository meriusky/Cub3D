/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_mapinfo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:23:26 by mehernan          #+#    #+#             */
/*   Updated: 2024/10/08 17:47:01 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
//crear funcion para que en caso de error libere todo o simplemente hacer free
//cuando toque, no se que me ahorraria mas lineas
void	north_texture(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O')
	{
		while (line[i] != '\n')
		{
			if (line[i] == ' ' || line[i] == '	')
				i++;
			else if ((line[i] == '.' && line[i + 1] == '/') && line[i + 2] != '\0')
			{
				mapinfo->north = line;
				// COMPROBAR PATH, buscarlo en google
				printf("%s\n", line);
			//	return (0);
			}
		}
		printf("error: wrong north texture path\n");
		exit(1);
	}
	else
	{
		printf("ERROR: north textute information wrong\n");
//		return (1);
		exit(1);
	}
}

void	south_texture(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'S' && line[i + 1] == 'O')
	{
		while (line[i] != '\n')
		{
			if (line[i] == ' ' || line[i] == '	')
				i++;
			else if ((line[i] == '.' && line[i + 1] == '/') && line[i + 2] != '\0')
			{
				mapinfo->south = line;
				// COMPROBAR PATH, buscarlo en google
				printf("%s\n", line);
	//			return (0);
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
		while (line[i] != '\n')
		{
			if (line[i] == ' ' || line[i] == '	')
				i++;
			else if ((line[i] == '.' && line[i + 1] == '/') && line[i + 2] != '\0')
			{
				mapinfo->west = line;
				// COMPROBAR PATH, buscalo en google
				printf("%s\n", line);
	//			return (0);
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
		while (line[i] != '\n')
		{
			if (line[i] == ' ' || line[i] == '	')
				i++;
			else if ((line[i] == '.' && line[i + 1] == '/') && line[i + 2] != '\0')
			{
				mapinfo->east = line;
				//COMPROBAR PATH, buscar en google
				printf("%s\n", line);
//				return (0);
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

// importante: he quitado el contador a 0 porque en sorter me estoy saltando
// los espacios que pueda haber antes (tambien podria haber otras cosas que 
// no estoy comtemplado en el sorter, queda pendiente aclarar eso

// estoy haciendo que si las dos primeras letras no encajan que de error,
// sinceramente no se si el mapa es: N   O./path_lo_que_sea   esta mal
// doy por hecho que si. En caso de que este bien pues modificaria
// la estring para ponerla decente e ignorar los espacios.
