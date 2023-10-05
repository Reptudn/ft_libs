/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 01:44:44 by jonask            #+#    #+#             */
/*   Updated: 2023/10/05 01:52:48 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	strlcat(char *dst, const char *src, size_t size)
{
	int	i;
	int	d_len;

	i = 0;
	d_len = 0;
	while (dst[d_len] != 0)
		d_len++;
	while (dst[d_len + i] != 0 && src[i] != 0)
	{
		if ((d_len + i) < size)
			dst[d_len + i] = src[i];
		else if ((d_len + i) == size)
			dst[d_len + i] = 0;
		i++;
	}
	return (i);
}
