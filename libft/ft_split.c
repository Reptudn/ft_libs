/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:39:55 by jonask            #+#    #+#             */
/*   Updated: 2023/10/12 14:39:00 by jkauker          ###   ########.fr       */
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
		{
			while (s[count] == splitter)
				count++;
			words++;
		}
		count++;
	}
	return (words);
}

static void	cleanup(char **strs, int allocated_word_cnt)
{
	while (allocated_word_cnt > 0)
		free(strs[--allocated_word_cnt]);
	free(strs);
}

static int	get_word_len(char *word, char splitter)
{
	int	i;

	i = 0;
	while (word[i] != 0 && word[i] != splitter)
		i++;
	return (i);
}

static int	the_split(char c, const char *s, char **strs, int i)
{
	int	j;
	int	curr_word_len;
	int	str_index;

	str_index = 0;
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		curr_word_len = get_word_len((char *)&s[i], c);
		strs[str_index] = malloc(sizeof(char) * (curr_word_len + 1));
		if (!strs[str_index])
		{
			cleanup(strs, str_index);
			return (0);
		}
		j = 0;
		while (s[i] != c && s[i] != 0)
			strs[str_index][j++] = s[i++];
		strs[str_index][j] = 0;
		str_index++;
	}
	if (&s[i] != ft_strrchr(&s[i], c))
		ft_strlcpy(strs[str_index], &s[i], get_word_len((char *)&s[i], c));
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	int		i;

	strs = malloc((get_word_count(s, c)) * sizeof(char *));
	if (!strs)
		return (0);
	if (ft_strchr(s, c) == 0)
	{
		*strs = ft_strdup(s);
		return (strs);
	}
	i = 0;
	if (!the_split(c, s, strs, i))
		return (0);
	return (strs);
}
