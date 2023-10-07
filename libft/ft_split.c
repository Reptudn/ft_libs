/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:39:55 by jonask            #+#    #+#             */
/*   Updated: 2023/10/07 18:30:52 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

!!!
//what if two splitters are next to each other?

#include <stdlib.h>

int	get_word_count(const char *s, char splitter)
{
	int	count;
	int	words;

	words = 0;
	count = 0;
	while(s[count] != 0)
	{
		if (s[count] == splitter)
			words++;
		count++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	char	*str;
	int		i;
	int		j;
	int		k;

	strs = malloc(get_word_count(s, c) + 1);
	if (!strs)
		return (0);
	i = 0;
	j = 0;
	k = 0;
	while(s[i] != 0)
	{
		while(s[i + k] != 0 && s[i + k] != c)
			k++;
		strs[j] = malloc((k + 1) * sizeof(char));
		if (!strs[j])
		{
			i = 0;
			while (strs[i] != 0 || i < get_word_count(s, c))
				free(strs[i++]);
			return (0);
		}
		k = 0;
		while (strs[j][k] != 0)
			strs[j][k++] = s[i++];
		if(s[i] == c)
			j++;
		i++;
	}
	return (strs);
}
