/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 08:33:01 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/06 09:23:59 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>

char	*read_file(int fd, char *str)
{
	char	buffer[BUFFER_SIZE + 1];
	long	read_amount;
	size_t	start;

	start = 0;
	read_amount = 0;
	while (!ft_strchr(buffer, '\n'))
	{
		read_amount = read(fd, buffer, BUFFER_SIZE);
		buffer[read_amount] = 0;
		printf("buffer: %s\n", buffer);
		if (read_amount == -1)
			return (0);
		if (read_amount == 0)
			break ;
		str = strjoin(str, buffer);
		printf("new str: %s\n", str);
		if (!str)
			return (0);
	}
	while(str[start] != '\n' && str[start] != 0)
		start++;
	start++;
	return (substr(str, start, ft_strchr(str, '\n') - str + 1));
}

char	*get_next_line(int fd)
{
	static char	*str = 0;
	char		*line;

	if (fd <= 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (0);
	line = read_file(fd, str);
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
