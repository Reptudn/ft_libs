/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:26:36 by jonask            #+#    #+#             */
/*   Updated: 2023/10/15 16:13:51 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>

# define READ_ERR -1
# define EOF 0

char	*get_next_line(int fd);
size_t	get_buffer_length_dynamic(int fd);
char	*get_file_content(int fd);
char	*create_next_line_str(char	*content, char *last_nl);

#endif