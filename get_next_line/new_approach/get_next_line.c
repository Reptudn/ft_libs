/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 08:33:01 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/04 08:47:23 by jkauker          ###   ########.fr       */
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
	size_t	read_amount;

	read_amount = 0;
	buffer[BUFFER_SIZE] = 0;
	while (read_amount > 0 && !ft_strchr(buffer, '\n'))
	{
		read_amount = read(fd, buffer, BUFFER_SIZE);
		if (read_amount == -1)
			return (0);
		// add to str
	}
	// cut away the part form beginning until the nl into line
	// dont forget to null terminate everything
	// return line
}

char	*get_next_line(int fd)
{
	static char	*str = 0;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (0);
	line = read_file(fd, str);
	return (line);
}
