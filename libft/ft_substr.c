/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:14:09 by jonask            #+#    #+#             */
/*   Updated: 2023/10/11 10:06:34 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	int		size;
	char	*sub;
	int		i;

	if (start >= len || len == 0)
		return (0);
	if (!s)
		return (0);
	size = len - start;
	sub = malloc((size + 1) * sizeof(char));
	if (!sub)
		return (0);
	i = 0;
	while (s[start + i] != 0 && i < size)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[len] = 0;
	return (sub);
}
