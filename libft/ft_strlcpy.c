/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 01:37:45 by jonask            #+#    #+#             */
/*   Updated: 2023/10/10 13:21:01 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	total;

	i = 0;
	if (size == 0)
		return (ft_strlen(dst));
	while (src[i] != 0 && i < size)
	{
		if (src[i] == 0)
			break ;
		if (ft_isspace(src[i]))
			i++;
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	total = i + ft_strlen(src + i);
	return (total);
}
