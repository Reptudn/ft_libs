# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonask <jonask@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 12:22:34 by jonask            #+#    #+#              #
#    Updated: 2023/10/08 22:18:53 by jonask           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

!!!
NEED THE RIGHT SOURCES AND THEN ALL COMPILE THEM TO OBJ FILES THEN
MAKE THE LIB CALLED "libft" THEN DELETE ALL THE OBJ FILES AGAIN

COMMANDS?
cc *.c
ar -rc libft.a *.o

!!!

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra
CFILES = (wildcard *.c)

OBJ = ?

SRCS = $(OBJ:%.o=%.c)

clean:
	rm -rf $(OBJ)

test: $(SRCS)
	cc -o $@ $(CFLAGS) $(SRCS)