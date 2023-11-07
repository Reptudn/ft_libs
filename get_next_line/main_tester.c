/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:42:21 by jkauker           #+#    #+#             */
/*   Updated: 2023/11/07 16:11:53 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main()
{
    int fd = open("./tests/alternate_line_nl_with_nl", O_RDONLY);
	int i = 0;
	char *p = 0;
	while (i < 10)
	{
		p = get_next_line(fd);
		printf("-----------------------\n");
		printf("%s", p);
		free(p);
		i++;
	}
	printf("%s\n", p);
	close(fd);
}
