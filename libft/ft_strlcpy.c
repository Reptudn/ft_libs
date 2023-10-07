/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 01:37:45 by jonask            #+#    #+#             */
/*   Updated: 2023/10/05 01:47:55 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;

	i = 0;
	while (src[i] != 0)
	{
		if (i < size)
			dst[i] = src[i];
		else if (i == size)
			dst[i] = 0;
		i++;
	}
	return (i);
}
