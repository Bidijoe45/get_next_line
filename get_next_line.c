/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:15:29 by apavel            #+#    #+#             */
/*   Updated: 2020/01/23 10:58:10 by apavel           ###   ########.fr       */
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
	if (fd == -1)
		return (-1);
	while (ft_exists_new_line(buff) == 0)
	{
		write(1, buff, BUFFER_SIZE);
		b = read(fd, &buff, BUFFER_SIZE);
	}
		
	return 0;
}

int main()
{
	char	*line;
	int arch = open("arch", O_RDONLY);
	
	get_next_line(arch, &line);
	
	//char *str = "Hola que tal";
	//printf("%d", ft_exists_new_line(str));
}
