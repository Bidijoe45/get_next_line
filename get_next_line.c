/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:15:29 by apavel            #+#    #+#             */
/*   Updated: 2020/01/30 14:08:16 by apavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int get_next_line(int fd, char **line)
{
	static char	*stack[4092];
	char buff[BUFFER_SIZE + 1];
	char *tmp_str;
	int	b;	
	
	if (fd < 0 || read(fd, buff, 0) == -1 || !line)
		return (-1);
	
	/*
	 *	------
	 * Hola que
	 * que tal
	 *	-------
	 *	
	 *	BUFF: Hola que\nque tal
	 *	STATIC: 
	 *
	 *	LINE: Hola que\0
	 *
	 *
	 *
	 */

	//Comprobar si hay algo en static
	

	//Leer archivo y guardar hasta /n
	
	while ((b = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[b] = '\0';
		//Si existe un salto de linea em buff salimos del bucle
		//	if (!stack[fd])
		//		stack[fd] = ft_strdup(buff);
//			
		if (ft_get_new_line(buff) == -1)
		{
//			if (!stack[fd])
//				stack[fd] = ft_strdup(buff);
//			else
//			{
				tmp_str = ft_strdup(stack[fd]);
				free(stack[fd]);
				stack[fd] = ft_strjoin(tmp_str, buff);
				free(tmp_str);
//			}
		}
		else
		{
			*line = ft_substr(stack[fd], 0, ft_get_new_line(stack[fd]));
			free(stack[fd]);
	//		tmp_str = ft_strdup(&buff[ft_get_new_line(buff)])
	//		stack[fd] = ft_strdup(tmp_str);
			break ;
		}
	
	}

	return (1);
}


int main()
{

    int             fd;
    int             i;
    int             j;
    char            *line = 0;
    char            *lineadress[66];

    j = 1;

    printf("\n==========================================\n");
    printf("========== TEST 1 : The Alphabet =========\n");
    printf("==========================================\n\n");

    if (!(fd = open("arch", O_RDONLY)))
    {
        printf("\nError in open\n");
        return (0);
    }
    while ((i = get_next_line(fd, &line)) > 0)
    {
        printf("i: %d |%s|\n", i, line);
        lineadress[j - 1] = line;
        j++;
    }
	printf("i: %d |%s|\n", i, line);
    free(line);
    close(fd);

    if (i == -1)
        printf ("\nError in Fonction - Returned -1\n");
    else if (j == 66)
        printf("\nRight number of lines\n");
    else if (j != 66)
        printf("\nNot Good - Wrong Number Of Lines\n");
    while (--j > 0)
        free(lineadress[j - 1]);

	return (1);
}
