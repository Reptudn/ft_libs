CC = cc
CFLAGS = -Wall -Werror -Wextra -I ./

SRCS = ft_printf.c conversion.c base_system_conversion.c helper.c
OBJS = $(SRCS:.c=.o)

NAME = libprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

re:
	fclean all

clean:
	rm -f $(OBJS) $(NAME)

fclean:clean
	rm -rf $(OBJ)

.PHONY all clean clean