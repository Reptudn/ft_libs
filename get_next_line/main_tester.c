/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:42:21 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/06 09:12:53 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main()
{
    int fd = open("texttest.txt", O_RDONLY);
	printf("file read\n");
	for (int i = 0; i < 14; i++)
	{
		printf("%s", get_next_line(fd));
	}
	close(fd);
}
