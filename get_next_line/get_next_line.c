/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:26:38 by jonask            #+#    #+#             */
/*   Updated: 2023/11/02 17:49:57 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
#include <stddef.h>

void	clean_static(char *left, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		left[i] = 0;
		i++;
	}
	if (left)
	{
		free(left);
		left = NULL;
	}
}
// cuts away the left part of the string by size and meaybe realloctes it too
void	ft_strcut(char	*left, size_t len)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	j = 0;
	temp = malloc((ft_strlen(left) - len + 1) * sizeof(char));
	if (!temp)
		return ;
	while (left[i] != '\0')
	{
		if (i >= len)
		{
			temp[j] = left[i];
			j++;
		}
		i++;
	}
	temp[j] = '\0';
	clean_static(left, ft_strlen(left));
	left = ft_realloc(temp, ft_strlen(temp));
}

void	*ft_realloc(void *old, size_t new_size)
{
	char	*temp;

	if (!*((char *)old))
	{
		old = malloc(1);
		((char *)old)[0] = '\0';
	}
	temp = malloc(new_size + 1);
	if (!temp)
		return (old);
	temp = ft_memcpy(temp, old, new_size);
	if (old)
	{
		clean_static(old, ft_strlen(old));
		return (NULL);
	}
	return (temp);
}

int	ft_read(int fd, char **left)
{
	char	buffer[BUFFER_SIZE + 1];
	int		read_len;

	if (!*left)
	{
		*left = malloc (BUFFER_SIZE * sizeof(char));
		if (!*left)
			return (0);
		*left[0] = '\0';
	}
	buffer[BUFFER_SIZE] = 0;
	while (!ft_strchr(buffer, '\n'))
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		if (read_len < 1)
			return (0);
		*left = ft_realloc(*left, ft_strlen(*left) + read_len + 2);
		if (!*left)
		{
			clean_static((char *)*left, BUFFER_SIZE + 1);
			return (0);
		}
		ft_strlcat(*left, buffer, ft_strlen(*left) + read_len + 1);
	}
	(*left)[ft_strlen(*left) + read_len + 1] = 0;
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
		if (ft_strlen(left) == 0)
			return (0);
		return (left);
	}
	len = ft_strchr(left, '\n') - left + 1;
	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (0);
	tmp = ft_memcpy(tmp, left, len + 1);
	tmp[len] = 0;
	if (left)
		ft_strcut(left, ft_strchr(left, '\n') - left + 1);
	return (tmp);
}

/*
Neu coden

probably moving the pointer is a problem that i cant free the things
from before the moving pointer after moving it -> gotta make a func
that really clears up the string correctly ()
*/