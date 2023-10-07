/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 00:43:43 by jonask            #+#    #+#             */
/*   Updated: 2023/10/05 01:02:45 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*last_occ;

	i = 0;
	last_occ = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			last_occ = &s[i];
		i++;
	}
	return ((char *)last_occ);
}
