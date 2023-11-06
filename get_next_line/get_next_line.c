/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:46:57 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/03 16:37:47 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	sub[len] = 0;
	return (sub);
}

char	*get_line_mine(int fd, char **str)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	read_bytes;
	size_t	size;
	char	*line;
	char 	*tmp;

	buffer[BUFFER_SIZE] = 0;
	while (!ft_strchr(buffer, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			if (*str != 0 && **str != 0)
				return (ft_strdup(*str));
			if (*str != 0)
			{
				free(*str);
				*str = 0;
			}
			return (0);
		}
		buffer[read_bytes] = 0;
		tmp = ft_strjoin(*str, buffer);
		free(*str);
		*str = tmp;
	}
	if (**str == '\0')
		return (0);
	if (!ft_strchr(*str, '\n'))
		size = ft_strlen(*str) + 1;
	else
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
	line = get_line_mine(fd, &string);
	if (!string)
	{
		free(line);
		return (NULL);
	}
	string = ft_substr(string, ft_strlen(line), BUFFER_SIZE);
	if (!string)
	{
		free(line);
		return (0);
	}
	if (!line)
		return (0);
	return (line);
}
