/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:23:41 by jonask            #+#    #+#             */
/*   Updated: 2023/10/06 10:40:51 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
!!!

#include <stdlib.h>

int	getlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

int	substrcmp(const char *s1, const char *s2, int start_index)
{
	int	i;

	i = 0;
	while (s1[start_index + i] != 0 && s2[i] != 0)
	{
		if (s1[start_index + i] != s2[i])
			return (-1);
		i++;
	}
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	char	*str;
	int		first;
	int		last;
	int		is_word;
	int		t;

	i = 0;
	is_word = 0;
	last = 0;
	if (s1 == 0)
		return (0);
	first = s1[0];
	while (s1[i] != 0)
	{	
		last = i;
		t = substrcmp(s1, set, i)
		if (t == -1)
			is_word == 1;
		if (is_word == 0 && t > 0)
		{

			i += t - 1;
		}
		i++;
	}
	str = malloc((set_count + 1) * sizeof(char));
	str[i] = 0;
	return (str);
}
