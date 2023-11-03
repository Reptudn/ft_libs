/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:46:57 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/03 14:26:46 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:55:44 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/03 10:12:05 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] != 0 && (i + 1 < size))
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = 0;
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*dst != 0 && i < size)
	{
		i++;
		dst++;
	}
	return (ft_strlcpy(dst, src, size - i) + i);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dup)
		return (0);
	while (s[i] != 0)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		total_len;
	int		i;
	int		j;
	char	*joined;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined = malloc(total_len * sizeof(char));
	if (!joined)
		return (0);
	ft_strlcpy(joined, s1, total_len);
	ft_strlcat(joined, s2, total_len);
	return (joined);
}


#include "get_next_line.h"
#include <stddef.h>
#include <sys/_types/_ssize_t.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}

void	makesub(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] != 0 && (i + 1 < size))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (0);
	if (start >= ft_strlen(s) || (start == 0 && len == 0))
		return (ft_strdup(""));
	if (start == 0 && len >= ft_strlen(s))
		return (ft_strdup(s));
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (0);
	makesub(sub, s + start, len + 1);
	sub[len + 1] = 0;
	return (sub);
}

char	*get_line(int fd, char **str)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	read_bytes;
	size_t	size;
	char	*line;

	buffer[BUFFER_SIZE] = '\0';
	while (!ft_strchr(buffer, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			if (*str != 0 && **str != 0)
				return (ft_strdup(*str));
			free(*str);
			free(str);
			*str = 0;
			return (0);
		}
		buffer[read_bytes] = '\0';
		*str = ft_strjoin(*str, buffer);
	}
	if (**str == '\0')
		return (0);
	size = ft_strchr(*str, '\n') - *str + 1;
	line = malloc((size + 1) * sizeof(char));
	ft_strlcpy(line, *str, size + 1);
	line[size] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*string = 0;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
		return (0);
	if (!string)
	{
		string = malloc(1 * sizeof(char));
		if (!string)
			return (0);
		string[0] = '\0';
	}
	line = get_line(fd, &string);
	if (!string || string[0] == 0)
		return (NULL);
	string = ft_substr(string, ft_strlen(line), BUFFER_SIZE);
	if (!string)
	{
		free(string);
		return (0);
	}
	if (!line || line[0] == '\0')
		return (0);
	return (line);
}
#include <stdio.h>
int main()
{
    int fd = open("texttest.txt", O_RDONLY);
	for (int i = 0; i < 20; i++)
	{
		printf("%s", get_next_line(fd));
	}
	close(fd);
}
