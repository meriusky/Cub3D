/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:25:28 by mehernan          #+#    #+#             */
/*   Updated: 2024/10/08 18:02:31 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

void	floor_color(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'F')
	{
		while (line[i] != '\0')// loop infinito ERROR
		{
			if (line[i] == ' ' || line[i] == '	')
				i++;
			if (line[i] >= '0' && line[i] <= '9')
			{
				rgb_checker(line, i);
				mapinfo->floor = line;
				printf("%s\n", line);
			}
		}
	}
	else
	{
		printf("ERROR: floor color information wrong\n");
		exit(1);
	}
}

void	ceiling_color(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'C')
{
		printf("entro if C\n");
		printf("%s\n", line);
		while (line[i] != '\0')// loop infinito ERROR
		{
			printf("%c\n", line[i]);
			if (line[i] == 32)// || line[i] == '	') // possible error if 💀
			{
				printf("😵‍💫\n");
				i++;
			}
			printf("antes del if del rgb");
			if (line[i] >= 48 && line[i] <= 57)
			{
				printf("antes de entrar rgb checker\n");
				rgb_checker(line, i);
				mapinfo->floor = line;
				printf("%s\n", line);
//				return (0);
			}
			else
			{
					printf("ERROR: unexpected char not allowed\n");
					exit(1);
			}
		}
	}
	else
	{
		printf("ERROR: floor color information wrong\n");
//		return (1);
		exit(1);
	}
}
//💀parece ser que el while infinito esta apanyado, sospecho que el problema se
//encuentra en la lectura de los caracteres la cual no llega al if de los numeros
// ya que no encuentra el espacio. Sinceramente creo que el mapa de ejemplo esta 
// bien escrito o quizas puede ser un problema que en linux no me de o algo asi, 
// deberia probarlo en el campus pero vaya. Otra opcion esque no este escribiendo 
// la condicion de los espacios bien.
