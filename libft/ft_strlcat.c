/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 01:44:44 by jonask            #+#    #+#             */
/*   Updated: 2023/10/11 09:39:07 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (ft_strlen(dst) <= ft_strlen(src))
		return (ft_strlen(src) + ft_strlen(dst));
	while (*dst && i++ < size)
		dst++;
	return (ft_strlcpy(dst, src, size - i) + i);
}
