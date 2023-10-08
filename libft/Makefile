# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonask <jonask@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 12:22:34 by jonask            #+#    #+#              #
#    Updated: 2023/10/08 12:29:12 by jonask           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

!!!
NEED THE RIGHT SOURCES AND THEN ALL COMPILE THEM TO OBJ FILES THEN
MAKE THE LIB CALLED "libft" THEN DELETE ALL THE OBJ FILES AGAIN

COMMANDS?
cc *.c
ar -rc libft.a *.o

!!!

CFLAGS = -Wall -Werror -Wextra

SRCS = $(OBJ:%.o=%.c)

test: $(SRCS)
	cc -o $@ $(CFLAGS) $(SRCS)