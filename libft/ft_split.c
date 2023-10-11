/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:39:55 by jonask            #+#    #+#             */
/*   Updated: 2023/10/11 22:02:38 by jonask           ###   ########.fr       */
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
			while(s[count] == splitter)
				count++;
			words++;
		}
		count++;
	}
	return (words + 1);
}

static void	cleanup(char **strs, int allocated_word_cnt)
{
	while(allocated_word_cnt > 0)
		free(strs[allocated_word_cnt--]);
	free(strs);
}

static int	the_split(char c, const char *s, char **strs)
{
	int	i;
	int	j;
	int	curr_word_len;
	int	str_index;

	i = 0;
	str_index = 0;
	while(s[i] != 0)
	{
		curr_word_len = 0;
		while(s[i + curr_word_len] != 0 && s[i + curr_word_len] != c)
		{
			i++;
			curr_word_len++;
		}
		if (s[i + curr_word_len] == 0)
			break ;
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
	strs[str_index] = 0;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**strs;

	strs = malloc((get_word_count(s, c)) * sizeof(char *));
	if (!strs)
		return (0);
	if(!the_split(c, s, strs))
		return (0);
	return (strs);
}
