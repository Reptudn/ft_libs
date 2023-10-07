/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:26:28 by jkauker           #+#    #+#             */
/*   Updated: 2023/10/06 10:54:55 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*memset(void *b, int c, size_t len)
{
	unsigned char	_c;
	int				i;

	_c = c;
	i = 0;
	while (i < len)
	{
		((char *)b)[i++] = _c;
	}
	return (b);
}
