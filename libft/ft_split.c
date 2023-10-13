/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:39:55 by jonask            #+#    #+#             */
/*   Updated: 2023/10/13 11:14:31 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_word_count(const char *s, char splitter)
{
	int	count;
	int	words;

	words = 0;
	count = 0;
	while (s[count] != 0)
	{
		while (s[count] == splitter)
			count++;
		if (s[count] != 0 && s[count] != splitter)
			words++;
		while (s[count] != splitter && s[count] != 0)
			count++;
	}
	return (words);
}

static void	split_strcpy(char *dest, const char *src, char splitter)
{
	int	i;

	i = 0;
	while (src[i] != 0 && src[i] != splitter)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

static void	cleanup(char **strs, int allocated_word_cnt)
{
	while (allocated_word_cnt > 0)
		free(strs[--allocated_word_cnt]);
	free(strs);
}

static int	the_split(int c, const char *s, char **strs, int i)
{
	char	*element;
	int		word_count;
	int		max;

	max = i;
	word_count = 0;
	i = 0;
	while (*s && !(*s == c && s + 1 == 0) && word_count < max)
	{
		i = 0;
		while (*s == c)
			s++;
		while (s[i] != c && s[i] != 0)
			i++;
		element = malloc(sizeof(char) * (i + 1));
		if (!element)
		{
			cleanup(strs, word_count - 1);
			return (0);
		}
		split_strcpy(element, s, c);
		strs[word_count++] = element;
		s += i;
	}
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	int		words;

	words = get_word_count(s, c);
	if (!c)
	{
		strs = malloc(2 * sizeof(char *));
		if (!strs)
			return (0);
		strs[0] = ft_strdup(s);
		strs[1] = 0;
		return (strs);
	}
	strs = malloc((words + 1) * sizeof(char *));
	if (!strs)
		return (0);
	strs[words] = 0;
	if (!the_split(c, s, strs, words))
		return (0);
	return (strs);
}

// int	main(void)
// {
// 	char **strs = ft_split("      split       this for   me  !       ", ' ');
// 	for (int i = 0; strs[i] != 0; i++)
// 	{
// 		printf("%s\n", strs[i]);
// 	}
// 	return (0);
// }
