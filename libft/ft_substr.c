/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:14:09 by jonask            #+#    #+#             */
/*   Updated: 2023/10/07 17:34:00 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

!!!

#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	int		size;
	char	*sub;
	int		i;

	if (start >= len)
		return (0);
	size = len - start;
	sub = malloc((size + 1) * sizeof(char));
	if (!sub)
		return (0);
	i = 0;
	while(s[start + i] != 0 && i < size)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}
