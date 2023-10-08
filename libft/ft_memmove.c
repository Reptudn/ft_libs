/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 00:38:12 by jonask            #+#    #+#             */
/*   Updated: 2023/10/08 21:51:45 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

!!!
check overlapping

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*temp;

	i = 0;
	temp = src;
	if (dest == 0 || src == 0)
		return (0);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		((char *)src)[i] = 0;
		i++;
	}
	return (dest);
}
