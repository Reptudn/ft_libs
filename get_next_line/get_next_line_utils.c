/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:21:49 by jonask            #+#    #+#             */
/*   Updated: 2023/10/31 15:08:14 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
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

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	i = 0;
	tmp_dest = dest;
	tmp_src = (unsigned char *)src;
	if (dest == 0 && src == 0)
		return (dest);
	while (i < n)
	{
		tmp_dest[i] = tmp_src[i];
		i++;
	}
	return (dest);
}

void	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*dst != 0 && i < size)
	{
		i++;
		dst++;
	}
	dst = ft_memcpy(dst, src, size - i);
}

void	*ft_realloc(void	*old, size_t new_size)
{
	char	*temp;

	if (!*((char *)old))
	{
		old = malloc(1);
		*((char *)old) = '\0';
	}
	temp = malloc(new_size);
	if (!temp)
		return (old);
	temp = ft_memcpy(temp, old, ft_strlen((char *)old));
	free(old);
	return (temp);
}
