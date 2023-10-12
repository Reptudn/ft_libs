/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:16:43 by jkauker           #+#    #+#             */
/*   Updated: 2023/10/12 12:33:57 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start_index;
	size_t	end_index;
	char	*trimmed;

	start_index = 0;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[start_index]) != 0)
		start_index++;
	if (ft_strlen(s1) >= start_index)
		return (ft_strdup(""));
	end_index = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[end_index]) != 0 && end_index > start_index)
		end_index--;
	trimmed = malloc(sizeof(char) * (end_index - start_index + 2));
	if (!trimmed)
		return (0);
	ft_strlcpy(trimmed, s1 + start_index, end_index - start_index + 2);
	return (trimmed);
}

// int main()
// {
//     printf("%s\n", ft_strtrim(" lorem ipsum dolor sit amet", "l "));

//     return 0;
// }
