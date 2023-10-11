/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:14:09 by jonask            #+#    #+#             */
/*   Updated: 2023/10/11 11:50:46 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*make_substring(const char *s, char *sub, int start, size_t size)
{
	size_t	i;

	i = 0;
	while (s[start + i] != 0 && i < size)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	int		size;
	char	*sub;

	if (start >= ft_strlen(s) || len == 0)
	{
		sub = malloc(1);
		if (!sub)
			return (0);
		sub[0] = 0;
		return (sub);
	}
	if (!s)
		return (0);
	size = len - start;
	sub = malloc((size + 1) * sizeof(char));
	if (!sub)
		return (0);
	return (make_substring(s, sub, start, len));
}
