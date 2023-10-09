/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 00:38:12 by jonask            #+#    #+#             */
/*   Updated: 2023/10/09 10:15:38 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)src;
	if (dest == 0 || src == 0)
		return (0);
	while (n >= 0)
	{
		((char *)dest)[n] = ((char *)src)[n];
		((char *)src)[n] = 0;
		n--;
	}
	return (dest);
}
