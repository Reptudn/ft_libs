/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 00:43:43 by jonask            #+#    #+#             */
/*   Updated: 2023/10/10 12:58:48 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last_occ;

	i = 0;
	last_occ = 0;
	if (c == 0)
		return ((char *)s);
	while (s[i] != 0)
	{
		if (s[i] == c)
			last_occ = &(((char *)s)[i]);
		i++;
	}
	return (last_occ);
}
