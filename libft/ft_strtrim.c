/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:16:43 by jkauker           #+#    #+#             */
/*   Updated: 2023/10/11 17:31:27 by jkauker          ###   ########.fr       */
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
		i++;
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
	while (is_in_set(s1[ft_strlen(s1) - j], set))
		j++;
	return (ft_strlen(s1) - i - j);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trimmed;
	size_t	start_index;
	size_t	end_index;
	int		i;

	if (ft_strncmp(set, "", 1) != 0)
		return (ft_strdup(s1));
	trimmed = malloc((get_new_len(s1, set) + 1) * sizeof(char));
	if (!trimmed)
		return (0);
	start_index = 0;
	while (is_in_set(s1[start_index], set) == 1)
		start_index++;
	end_index = 0;
	while (is_in_set(s1[sizeof(s1) - end_index - 1], set) == 1)
		end_index++;
	if (start_index == end_index)
		return (0);
	i = 0;
	while (start_index < ft_strlen(s1) - end_index - 1)
		trimmed[i++] = s1[start_index++ + 1];
	trimmed[get_new_len(s1, set) + 1] = 0;
	return (trimmed);
}
