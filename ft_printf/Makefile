CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c conversion.c base_system_conversion.c helper.c
OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

.PHONY: all clean clean re

all: $(NAME)

$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -f $(NAME)
	
re: fclean all