/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:15:23 by apavel            #+#    #+#             */
/*   Updated: 2020/01/27 14:26:26 by apavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_get_new_line(char *str)
{
	size_t i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}

	return (-1);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *ptr;
    size_t  i;
    size_t  j;

    if (!s1 || !s2)
        return (NULL);
    if (!(ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
        return (NULL);
    i = -1;
    while (s1[++i] != '\0')
        ptr[i] = s1[i];
    j = i;
    i = -1;
    while (s2[++i] != '\0')
    {
        ptr[j] = s2[i];
        j++;
    }
    ptr[j] = '\0';
    return (ptr);
}

size_t  ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char    *ft_strdup(char *s1)
{
    char    *ptr;
    size_t  i;
    size_t  s1_len;

    s1_len = ft_strlen(s1);
    ptr = malloc(s1_len + 1);
    if (!ptr)
        return (NULL);
    i = 0;
    while (i < s1_len)
    {
        ptr[i] = s1[i];
        i++;
    }
    ptr[i] = '\0';
    return (ptr);
}

char    *ft_substr(const char *s, unsigned int start, size_t len)
{
    size_t          i;
    unsigned char   *u_s;
    unsigned char   *str;

    if (!s)
        return (NULL);
    if (*s == '\0')
        return (ft_strdup(""));
    if (!(str = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    if (ft_strlen(s) < start)
        return (ft_strdup(""));
    u_s = (unsigned char *)s;
    i = 0;
    while (u_s[start + i] != '\0' && i < len)
    {
        str[i] = u_s[start + i];
        i++;
    }
    str[i] = '\0';
    return (char *)str;
}
