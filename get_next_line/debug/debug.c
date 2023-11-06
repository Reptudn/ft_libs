/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 08:33:27 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/06 11:24:04 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

size_t	ft_strlen(char *s)
{
	size_t len;

	len = 0;
	if (!s || !*s)
		return (0);
	while (s[len] != 0)
		len++;
	return (len);
}

char	*ft_strchr(char *s, int c)
{
	while (*s != 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dup)
	{
		free(s);
		return (0);
	}
	while (s[i] != 0)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		free(s1);
		free(s2);
		return (0);
	}
	while (*s1 != 0)
		str[i++] = *s1++;
	while (*s2 != 0)
		str[i++] = *s2++;
	str[i] = 0;
	return (str);
}

char	*substr(char *s, unsigned int start, size_t len)
{
	char	*str;
    size_t	i;

    if (!s)
        return (0);
    if (start >= ft_strlen(s))
        return (ft_strdup(""));
    if (len > ft_strlen(s) - start)
        len = ft_strlen(s) - start;
    str = malloc(sizeof(char) * (len + 1));
    if (!str)
    {
        free(s);
        return (0);
    }
    i = 0;
    while (i < len && s[start + i])
    {
        str[i] = s[start + i];
        i++;
    }
    str[i] = 0;
    return (str);
}

char	*read_file(int fd, char **str)
{
	char	buffer[BUFFER_SIZE + 1];
	long	read_amount;
	char	*line;

	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	read_amount = 0;
	while (!ft_strchr(buffer, '\n'))
	{
		read_amount = read(fd, buffer, BUFFER_SIZE);
		if (read_amount == -1)
			return (0);
		if (read_amount == 0)
			break ;
		*str = strjoin(*str, buffer);
		if (!str)
			return (0);
	}
	if (*str == 0)
		return (0);
	line = substr(*str, 0, ft_strchr(*str, '\n') - *str + 1);
	*str = substr(*str, ft_strchr(*str, '\n') - *str + 1, BUFFER_SIZE);
	if (!*str)
	{
		free(*str);
		*str = 0;
		return (0);
	}
	buffer[0] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str = 0;
	char		*line;

	if (fd <= 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (0);
	line = read_file(fd, &str);
	if (!line)
	{
		if (str)
		{
			free(str);
			str = 0;
		}
		return (0);
	}
	return (line);
}

#include <fcntl.h>
int main()
{
    int fd = open("texttest.txt", O_RDONLY);
	for (int i = 0; i < 20; i++)
	{
		printf("%s", get_next_line(fd));
	}
	close(fd);
}