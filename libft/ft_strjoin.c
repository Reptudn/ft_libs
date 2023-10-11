/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:36:09 by jonask            #+#    #+#             */
/*   Updated: 2023/10/11 09:59:29 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		total_len;
	int		i;
	int		j;
	char	*joined;

	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	i = 0;
	j = 0;
	joined = malloc(total_len * sizeof(char));
	if (!joined)
		return (0);
	while (s1[i] != 0)
		joined[j++] = s1[i++];
	i = 0;
	while (s2[i] != 0)
		joined[j++] = s2[i++];
	joined[total_len] = 0;
	return (joined);
}
