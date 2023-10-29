/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:21:49 by jonask            #+#    #+#             */
/*   Updated: 2023/10/15 16:14:57 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_buffer_length_dynamic(int fd)
{
	size_t		bufflen;
	char		*readbuff;

	bufflen = 0;
	while(read(fd, readbuff, 1) != EOF)
		bufflen++;
	return (bufflen);
}

char	*create_next_line_str(char	*content, char *last_nl)
{
	int		line_length;
	char	*line;
	int		i;

	line_length = 0;
	last_nl++;
	while(last_nl[line_length] != '\n' && last_nl[line_length] != 0 && i < BUFFER_SIZE)
	{
		// malloc and read / get content
		line_length++;
		i++;
	}
	if (line_length == 0) //was already on end
		return (0);
	line = malloc(line_length * sizeof(char));
	if (!line)
		return (0);
	i = 0;
	while(i < line_length)
	{
		line[i] = last_nl[i];
		i++;
	}
	last_nl += line_length; //maybe -1 if its past the nl
	return (line);
}