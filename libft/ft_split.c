/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:39:55 by jonask            #+#    #+#             */
/*   Updated: 2023/10/13 10:34:29 by jkauker          ###   ########.fr       */
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
		while (s[count] != splitter && s[count] != 0)
			count++;
		words++;
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

	word_count = 0;
	while (*s && !(*s == c && s + 1 == 0))
	{
		i = 0;
		while (*s == c)
			s++;
		while (s[i] != c && s[i] != 0)
			i++;
		element = malloc(sizeof(char) * (i + 1));
		if (!element)
		{
			cleanup(strs, word_count);
			return (0);
		}
		split_strcpy(element, s, c);
		strs[word_count] = element;
		word_count++;
		s += i;
	}
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	int		i;

	strs = malloc((get_word_count(s, c)) * sizeof(char *));
	if (!strs)
		return (0);
	i = 0;
	if (!the_split(c, s, strs, i))
		return (0);
	return (strs);
}

// int	main(void)
// {
// 	char **strs = ft_split("    hi ad banana aple abc   ananas ", ' ');
// 	for (int i = 0; i < 6; i++)
// 	{
// 		printf("%s\n", strs[i]);
// 	}
// 	return (0);
// }
