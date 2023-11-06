/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 08:33:01 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/06 08:52:52 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>

char	*read_file(int fd, char *str)
{
	char	*line;
	char	buffer[BUFFER_SIZE + 1];
	long	read_amount;

	read_amount = 0;
	buffer[BUFFER_SIZE] = 0;
	while (!ft_strchr(buffer, '\n'))
	{
		printf("read");
		read_amount = read(fd, buffer, BUFFER_SIZE);
		if (read_amount == -1)
			return (0);
		if (read_amount == 0)
			break ;
		line = strjoin(str, buffer);
		if (!line)
			return (0);
	}
	str = substr(str, ft_strchr(str, '\n') - str + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str = 0;
	char		*line;

	printf("huh");
	if (fd <= 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (0);
	printf("lol");
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
