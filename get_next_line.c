/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:15:29 by apavel            #+#    #+#             */
/*   Updated: 2020/01/29 17:41:34 by apavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>


int get_next_line(int fd, char **line)
{
	static char	*rest[4092];
	char buff[BUFFER_SIZE + 1];
	int	b;
	char *tmp_str;

	if (fd < 0 || !fd || read(fd, buff, 0) < 0)
		return (-1);
	
	while ((b = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[b] = '\0';
		//printf("bytes read %d\n", b);
		if (ft_get_new_line(buff) == -1)
		{
			if (!rest[fd])
			{
				rest[fd] = ft_strdup(buff);
			}
			else
			{
				tmp_str = ft_strdup(rest[fd]);
				free(rest[fd]);
				rest[fd] = ft_strjoin(tmp_str, buff);
				free(tmp_str);
			}
		}
		else
		{
			tmp_str = ft_substr(buff, 0, ft_get_new_line(buff));
			*line = ft_strjoin(rest[fd], tmp_str);
			free(tmp_str);
			free(rest[fd]);
			rest[fd] = ft_substr(buff, ft_get_new_line(buff) + 1, ft_strlen(buff) - ft_get_new_line(buff));
			if (b < BUFFER_SIZE)
				return (0);
			return (1);
		}
	}

	return (0);
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
