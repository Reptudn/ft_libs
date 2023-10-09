/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:39:55 by jonask            #+#    #+#             */
/*   Updated: 2023/10/09 15:35:18 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_word_count(const char *s, char splitter)
{
	int	count;
	int	words;

	words = 0;
	count = 0;
	while (s[count] != 0)
	{
		if (s[count] == splitter)
			words++;
		count++;
	}
	return (words);
}

static int	the_split(int i, char c, const char *s, char **strs)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (s[i + k] != 0 && s[i + k] != c)
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
	while (strs[j][k] != 0 && s[i] != c)
		strs[j][k++] = s[i++];
	if (s[i] == c)
		j++;
	i++;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		k;

	strs = malloc(get_word_count(s, c) + 1);
	if (!strs)
		return (0);
	i = 0;
	j = 0;
	k = 0;
	while (s[i] != 0)
	{
		if (the_split(i, c, s, strs) == 0)
			return (0);
		i++;
	}
	return (strs);
}
