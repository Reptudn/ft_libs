/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:36:09 by jonask            #+#    #+#             */
/*   Updated: 2023/10/07 17:59:12 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

!!!

#include <stdio.h>
#include <stdlib.h>

int	getlen(const char *str)
{
	int len;

	len = 0;
	while(str[len] != 0)
		len++;
	return (len);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		total_len;
	int		i;
	int		j;
	char	*joined;

	total_len = getlen(s1) + getlen(s2);
	i = 0;
	j = 0;
	joined = malloc((total_len + 1) * sizeof(char));
	if (!joined)
		return (0);
	while(s1[i] != 0)
		joined[j] = s1[i++];
	i = 0;
	while(s2[i] != 0)
		joined[j] = s2[i++];
	joined[j] = 0;
	return (joined);
}
