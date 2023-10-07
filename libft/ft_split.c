/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:39:55 by jonask            #+#    #+#             */
/*   Updated: 2023/10/05 20:32:34 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

!!!

#include <stdlib.h>

char	**ft_split(const char *s, char c)
{
	int		last;
	int		i;
	int		word_count;
	char	**strs;
	char	*str;

	last = 0;
	while (s[last] != 0)
	{
		if (s[last] == c)
		{
			i = 0;
			while (s[last + i] != 0)
			{
				str = malloc()
			} 
		}
		last += i;
	}
	return (strs);
}
