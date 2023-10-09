# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 12:22:34 by jonask            #+#    #+#              #
#    Updated: 2023/10/09 11:05:17 by jkauker          ###   ########.fr        #
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
CFILES = 	ft_atoi.c 		ft_bzero.c 		ft_calloc.c 		ft_ascii.c 			ft_isalnum.c 	ft_isaplha.c 	/
			ft_isdigit.c 	ft_isprint.c
			ft_memchr.c 	ft_memcmp.c 	ft_memcpy.c 		ft_memmove.c 		ft_memset 		ft_putchar_fd.c /
			ft_putendl_fd.c ft_putnbr_fd.c 	ft_split.c 			ft_strchr.c 		ft_strdup.c 	ft_striter.c 	/
			ft_strjoin.c 	ft_strlcat.c 	ft_strlcpy.c 		ft_strlen.c 		ft_strmapi.c 	ft_strnstr.c 	/
			ft_strtrim.c 	ft_substr.c 	ft_tolower.c 		ft_toupper.c 		libft.h

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstmap.c

OBJ = $(CFILES:%.o=%.c)

all: $(NAME)

$(NAME): $(OBJ)
    ar -rc $(NAME) $(OBJ)

fclean:clean
	rm -r $(NAME)

doBonus:$(BONUS)
	cc $(CFLAGS) -c $< -o (<:.c=.o)

doBasic:$(CFILES)
	cc $(CFLAGS) -c $< -o (<:.c=.o)

re:
	fclean all

bonus:$(BONUS)

clean:
	rm -rf $(OBJ)

.PHONY fclean clean all re doBonus doBasic