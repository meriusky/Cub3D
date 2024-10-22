/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:25:28 by mehernan          #+#    #+#             */
/*   Updated: 2024/10/22 17:36:05 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

void	floor_color(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'F')
{
		printf("entro if F📔\n");
		printf("📔%s\n", line);
		printf("📔antes 1r ++: %c\n", line[i]);
		i++;
		printf("📔pre 1r while:%c\n", line[i]);
		while (line[i] != '\0')// loop infinito ERROR
		{
			printf("📔dentro 1r while: %c\n", line[i]);
			if (line[i] == 32)// || line[i] == '	') // possible error if 💀
			{
				printf("📔espacio💫\n");
				i++;
			}
//			i++;
			printf("📔antes del if del rgb\n");
			if (line[i] >= 48 && line[i] <= 57)
			{
				printf("📔antes de entrar rgb checker\n");
				if(rgb_checker(line, i) == 0) //esta funcion tiene que devolver algo para ↩️
					mapinfo->floor = line;//saber si hay que meterlo aqui.
				// hay que revisar que lleva la linea y que estamos metiendo⚠️
				printf("%s\n", line);
//				return (0);
			}
			else
			{
					printf("📔ERROR: unexpected char not allowed\n");
					exit(1);
			}
		}
	}
	else
	{
		printf("📔ERROR: floor color information wrong\n");
//		return (1);
		exit(1);
	}
}

/*{
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
}*/

void	ceiling_color(char *line, t_mapinfo *mapinfo, int i)
{
	if (line[i] == 'C')
{
		printf("entro if C\n");
		printf("%s\n", line);
		i++;
		printf("%c\n", line[i]);
		while (line[i] != '\0')// loop infinito ERROR
		{
			printf("%c\n", line[i]);
			if (line[i] == 32)// || line[i] == '	') // possible error if 💀
			{
				printf("espacio💫\n");
				i++;
			}
			i++;
//			printf("antes del if del rgb\n");
			if (line[i] >= 48 && line[i] <= 57)
			{
				printf("antes de entrar rgb checker\n");
				rgb_checker(line, i); //esta funcion tiene que devolver algo para ↩️
				mapinfo->ceiling = line;//saber si hay que meterlo aqui.
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
