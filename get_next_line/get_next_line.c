/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:26:38 by jonask            #+#    #+#             */
/*   Updated: 2023/11/02 12:24:07 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

int	ft_read(int fd, char **left)
{
	char	buffer[BUFFER_SIZE];
	int		read_len;

	if (!*left)
	{
		*left = malloc (100000 * sizeof(char));
		**left = '\0';
	}
	while (!ft_strchr(buffer, '\n'))
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		if (read_len < 1)
			return (0);
		//*left = ft_realloc(*left, ft_strlen(*left) + read_len + 2);
		//ft_strlcat(*left, buffer, ft_strlen(*left) + read_len + 1);
		ft_strlcat(*left, buffer, ft_strlen(*left) + read_len + 1);
	}
	(*left)[ft_strchr(*left, '\n') - *left + BUFFER_SIZE] = 0;
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*left;
	int			len;
	char		*tmp;

	if (fd == FD_ERR || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
		return (0);
	if (ft_read(fd, &left) == 0)
	{
		//left[BUFFER_SIZE + 1] = 0;
		return (left);
	}
	len = ft_strchr(left, '\n') - left + 1;
	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (0);
	tmp = ft_memcpy(tmp, left, len + 1);
	tmp[len] = 0;
	left += len;
	return (tmp);
}
