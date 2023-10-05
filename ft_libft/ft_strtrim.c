/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:23:41 by jonask            #+#    #+#             */
/*   Updated: 2023/10/05 12:39:47 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		j;
	int		set_count;
	char	*str;

	i = 0;
	j = 0;
	if (s1 == 0)
		return (0);
	while (s1[i] != 0)
	{
		if (s1[i] == s1[0] && substrcmp(s1, set, i))
		{
			i += getlen(set);
			continue ;
		}
		set_count++;
		i++;
	}
	str = malloc((set_count + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < set_count)
	{
		if (s1[i] == s1[0] && substrcmp(s1, set, i))
		{
			j += getlen(set);
			continue ;
		}
		str[i] = s1[j];
		i++;
	}
	str[i] = 0;
	return (str);
}
