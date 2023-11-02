/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:26:38 by jonask            #+#    #+#             */
/*   Updated: 2023/11/02 09:40:48 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

void	ft_read(int fd, char **left)
{
	char	buffer[BUFFER_SIZE];
	int		total;

	total = 0;
	if (!*left)
	{
		*left = malloc (10000000);
		**left = '\0';
	}
	while (!ft_strchr(buffer, '\n'))
	{
		if (read(fd, buffer, BUFFER_SIZE) < 1)
			break ;
		//*left = ft_realloc(*left, ft_strlen(*left) + read_len);
		ft_strlcat(*left, buffer, 10000000);
	}
	(*left)[ft_strchr(*left, '\n') - *left + BUFFER_SIZE] = 0;
}

char	*get_next_line(int fd)
{
	static char	*left;
	int			len;
	char		*tmp;

	if (fd == FD_ERR || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
		return (0);
	ft_read(fd, &left);
	len = ft_strchr(left, '\n') - left + 1;
	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (0);
	tmp = ft_memcpy(tmp, left, len + 1);
	tmp[len] = 0;
	left += len;
	return (tmp);
}
