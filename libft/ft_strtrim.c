/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:16:43 by jkauker           #+#    #+#             */
/*   Updated: 2023/10/11 10:03:35 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (set[i] == c)
			return (1);
	}
	return (0);
}

static int	get_new_len(const char *s1, const char *set)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (is_in_set(s1[i], set))
		i++;
	while (is_in_set(s1[sizeof(s1) - j], set))
		j++;
	return (sizeof(s1) - (i + j));
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trimmed;
	int		start_index;
	int		end_index;
	int		i;

	trimmed = malloc(get_new_len(s1, set));
	if (!trimmed)
		return (0);
	start_index = 0;
	while (is_in_set(s1[start_index], set))
		start_index++;
	end_index = 0;
	while (is_in_set(s1[sizeof(s1) - end_index - 1], set))
		end_index++;
	i = 0;
	while (start_index < end_index)
		trimmed[i++] = s1[start_index++];
	trimmed[i] = 0;
	return (trimmed);
}
