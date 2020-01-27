/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:15:29 by apavel            #+#    #+#             */
/*   Updated: 2020/01/27 14:29:07 by apavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>



int get_next_line(int fd, char **line)
{
	static char *resto;
	char buff[BUFFER_SIZE + 1];
	int	b;
	char *string;
	char *tmp_str;
	
	if (fd < 0)
		return (-1);
	string = 0;
	if (resto)
	{
		string = ft_strdup(resto);
		free(resto);
	}
	while ((b = read(fd, &buff, BUFFER_SIZE)))
	{
		buff[b] = '\0';
		if (ft_get_new_line(buff) == -1)
		{
			if (string == 0)
				string = ft_strdup(buff);
			else
			{
				tmp_str = ft_strdup(string);
				free(string);
				string = ft_strjoin(tmp_str, buff);
				free(tmp_str);
			}
		}
		else
		{
			resto = ft_substr(buff, ft_get_new_line(buff) + 1, b);
			*line = ft_strdup(string);
			free(string);
			return (1);
		}
	}
	
	return (0);
}

int main()
{
	char	*line;
	int arch = open("arch", O_RDONLY);
	printf("get return: %d\n", get_next_line(arch, &line));
	printf("String: |%s|\n", line);
	
	printf("get return: %d\n", get_next_line(arch, &line));
	printf("String: |%s|\n", line);
	
	printf("get return: %d\n", get_next_line(arch, &line));
	printf("String: |%s|\n", line);

	printf("get return: %d\n", get_next_line(arch, &line));
	printf("String: |%s|\n", line);

	printf("get return: %d\n", get_next_line(arch, &line));
	printf("String: |%s|\n", line);
	
	printf("get return: %d\n", get_next_line(arch, &line));
	printf("String: |%s|\n", line);
}


