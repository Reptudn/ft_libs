/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:42:21 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/02 10:58:41 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int fd = open("texttest.txt", O_RDONLY);
	for (int i = 0; i < 14; i++)
	{
		char *s = get_next_line(fd);
		printf("%s", s);
		free(s);
	}
		
	return (0);
}
