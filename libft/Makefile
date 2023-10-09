# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 12:22:34 by jonask            #+#    #+#              #
#    Updated: 2023/10/09 10:14:10 by jkauker          ###   ########.fr        #
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
CFILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_ascii.c ft_isalnum.c ft_isaplha.c /
			ft_isdigit.c ft_isprint.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c /
			ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJ = (wildcard *.o)

SRCS = $(OBJ:%.o=%.c)

clean:
	rm -rf $(OBJ)



test: $(SRCS)
	cc -o $@ $(CFLAGS) $(SRCS)