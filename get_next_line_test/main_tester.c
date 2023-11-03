/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:42:21 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/03 10:23:06 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main()
{
    int fd = open("texttest.txt", O_RDONLY);
	for (int i = 0; i < 14; i++)
	{
		printf("%s", get_next_line(fd));
	}
	close(fd);
}
