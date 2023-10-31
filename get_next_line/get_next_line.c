/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:26:38 by jonask            #+#    #+#             */
/*   Updated: 2023/10/31 14:57:46 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

void	ft_read(int fd, char **left)
{
	int		read_len;
	char	buffer[BUFFER_SIZE];

	read_len = 0;
	while (!ft_strchr(*left, '\n'))
	{
		if (read(fd, buffer, BUFFER_SIZE) < 1)
			break ;
		printf("buff: %s\n", buffer);
		*left = ft_realloc(*left, ft_strlen(*left) + BUFFER_SIZE);
		ft_strlcat(*left, buffer, BUFFER_SIZE);
	}
}

char	*get_next_line(int fd)
{
	static char	*left;
	int			len;
	char		*tmp;

	if (fd == FD_ERR || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
		return (0);
	if (!left)
	{
		left = malloc(1);
		left = "";
	}
	ft_read(fd, &left);
	printf("after read: %s\n", left);
	len = 0;
	while (left[len] != '\n')
		len++;
	len++;
	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (0);
	tmp = ft_memcpy(tmp, left, len);
	tmp[len] = 0;
	left += len + 1;
	return (tmp);
}
