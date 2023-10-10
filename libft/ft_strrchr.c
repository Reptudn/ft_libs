/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 00:43:43 by jonask            #+#    #+#             */
/*   Updated: 2023/10/10 17:19:33 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occ;

	last_occ = 0;
	while (*s != 0)
	{
		if (*s == (char)c)
			last_occ = (char *)s;
		s++;
	}
	if ((char)c == 0)
		return ((char *)s);
	return (last_occ);
}
