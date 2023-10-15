/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:26:38 by jonask            #+#    #+#             */
/*   Updated: 2023/10/15 16:14:12 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	When returning the line include the \n
*	When end of file dont return with \n
*/

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*last_line_end;
	char		*file_content;

	last_line_end = 0;
	if (fd == -1)
		return (0);
	file_content = get_file_content(fd);
	if (!file_content)
		return (0);
	return (create_next_line_str(file_content, last_line_end));
}