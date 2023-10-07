/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 01:58:37 by jonask            #+#    #+#             */
/*   Updated: 2023/10/07 16:22:33 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

!!!

#include <stdlib.h>

void	*ft_calloc(size_t nmenb, size_t size)
{
	if (nmenb == 0 || size == 0)
		return (malloc(0));
	if (nmenb * size > __INT_MAX__)
		return (0);
	return (malloc(nmenb * size));
}