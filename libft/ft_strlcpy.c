/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 01:37:45 by jonask            #+#    #+#             */
/*   Updated: 2023/10/09 15:31:58 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	total;

	i = 0;
	total = 0;
	while (dst[i++] != 0)
		total++;
	i = 0;
	while (src[i++] != 0)
		total++;
	i = 0;
	while (src[i] != 0 && i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (total + 1);
}
