/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:32:05 by jonask            #+#    #+#             */
/*   Updated: 2023/10/08 22:01:21 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
!!!

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	if (s == 0)
		return (0);
	i = 0;
	str = malloc(sizeof(s));
	if (!str)
		return (0);
	while(s[i] != 0)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
