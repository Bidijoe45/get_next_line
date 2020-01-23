/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:15:29 by apavel            #+#    #+#             */
/*   Updated: 2020/01/23 12:25:09 by apavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int get_next_line(int fd, char **line)
{
	static char *resto;
	char *string;
	char buff[BUFFER_SIZE];
	int	b;

	//Comprobar si pasan fd vacio
	if (fd < 0)
		return (-1);

	//Comprobar si hay algo en el resto y agregarlo al string
	
	while ((b = read(fd, buff, BUFFER_SIZE)) > 0)
	{		
		write(1, buff, BUFFER_SIZE);//DEBUG: imprime
		if (ft_get_new_line(buff) == 0)
		{
			string = ft_strjoin(string, buff);
			
		}
	}

	return (0);
}

int main()
{
	char	*line;
	int arch = open("arch", O_RDONLY);
	
	get_next_line(arch, &line);
	
	//char *str = "Hola\nque tal";
	//printf("%d", ft_exists_new_line(str));
}
