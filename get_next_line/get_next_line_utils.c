/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 08:33:27 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/06 09:27:35 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t len;

	len = 0;
	if (!s || !*s)
		return (0);
	while (s[len] != 0)
		len++;
	return (len);
}

char	*ft_strchr(char *s, int c)
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

char	*ft_strdup(char *s)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dup)
	{
		free(s);
		return (0);
	}
	while (s[i] != 0)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		free(s1);
		free(s2);
		return (0);
	}
	while (*s1 != 0)
		str[i++] = *s1++;
	printf("str; %s\n", str);
	while (*s2 != 0)
		str[i++] = *s2++;
	str[i] = 0;
	return (str);
}

char	*substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	len = ft_strlen(s) - start;
	str = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (!str)
	{
		free(s);
		return (0);
	}
	while (len--)
	{
		if (start == 0)
		{
			str[i] = s[i];
			i++;
			continue ;
		}
		start--;
	}
	str[i] = 0;
	return (str);
}
