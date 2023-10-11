/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 01:58:37 by jonask            #+#    #+#             */
/*   Updated: 2023/10/11 09:33:50 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmenb, size_t size)
{
	int		*pog;
	size_t	total;

	total = nmenb * size;
	if (total / size != nmenb)
		return (0);
	pog = malloc(total);
	if (!pog)
		return (0);
	ft_memset(pog, 0, total);
	return (pog);
}
