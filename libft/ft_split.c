/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:39:55 by jonask            #+#    #+#             */
/*   Updated: 2023/10/13 10:01:33 by jkauker          ###   ########.fr       */
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

static int	the_split(int c, const char *s, char **strs, int i)
{
	char	*element;
	int		word_count;

	word_count = 0;
	while (*s && !(*s == c && s + 1 == 0))
	{
		while (*s == c)
			s++;
		while (s[i] != c)
			i++;
		element = malloc(sizeof(char) * (i + 1));
		if (!element)
		{
			cleanup(strs, word_count);
			return (0);
		}
		ft_strlcpy(strs[word_count], s, i);
		s += i;
		word_count++;
	}
	return (1);
}

// static int	the_split(char c, const char *s, char **strs, int i)
// {
// 	int	j;
// 	int	curr_word_len;
// 	int	str_index;

// 	str_index = 0;
// 	while (s[i] != 0)
// 	{
// 		while (s[i] == c)
// 			i++;
// 		if (s[i] == 0)
// 		{
// 			strs[str_index] = ft_strdup(ft_strrchr(s, c) + 1);
// 			break ;
// 		}
// 		curr_word_len = get_word_len((char *)&s[i], c);
// 		strs[str_index] = malloc(sizeof(char) * (curr_word_len + 1));
// 		if (!strs[str_index])
// 		{
// 			cleanup(strs, str_index);
// 			return (0);
// 		}
// 		j = 0;
// 		while (s[i] != c && s[i] != 0)
// 			strs[str_index][j++] = s[i++];
// 		strs[str_index][j] = 0;
// 		str_index++;
// 	}
// 	return (1);
// }

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

int	main(void)
{
	char **strs = ft_split("    hi ad banana aple abc   ananas ", ' ');
	for (int i = 0; strs[i] != 0; i++)
	{
		printf("%s\n", strs[i]);
	}
	return (0);
}
