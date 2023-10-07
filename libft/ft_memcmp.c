/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 01:14:48 by jonask            #+#    #+#             */
/*   Updated: 2023/10/05 01:22:40 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	s1_count;
	int	s2_count;
	int	i;

	s1_count = 0;
	s2_count = 0;
	i = 0;
	while (i < n && ((char *)s1)[i] == ((char *)s2)[i])
	{
		s1_count += ((char *)s1)[i];
		s2_count += ((char *)s2)[i];
	}
	return (s1_count - s2_count);
}
