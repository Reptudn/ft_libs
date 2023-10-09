# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 12:22:34 by jonask            #+#    #+#              #
#    Updated: 2023/10/09 11:51:30 by jkauker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CFLAGS 	= -Wall -Werror -Wextra
CFILES 	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isascii.c ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striter.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strnstr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
BONUS 	= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c
OBJ 	= $(CFILES:.c=.o)
BONOBJ  = $(BONUS:.c=.o)
INCL	= ./
CC		= cc

all:$(NAME)

$(NAME):$(OBJ)
		ar -rcs $(NAME) $(OBJ)

$(OBJ):$(CFILES)
		$(CC) $(CFLAGS) -c $< -o $@ -I $(INCL)

fclean:clean
		rm -f $(NAME)

re:
		fclean all

bonus:$(BONUS)

$(BONOBJ):$(BONUS)
		cc $(CFLAGS) -c $< -o $@ -I $(INCL)

clean:
		rm -rf $(OBJ)