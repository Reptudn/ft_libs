/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:32:05 by jonask            #+#    #+#             */
/*   Updated: 2023/10/08 21:36:03 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

!!!

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	i = 0;
	while(s[i] != 0)
	{
		str = malloc(sizeof(f(i, s[i])));
		if (!str)
			return (0);
		i++;
	}
	return (str);
}
