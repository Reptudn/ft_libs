CC = cc
CFLAGS = -Wall -Werror -Wextra -I ./

SRCS = ft_printf.c ft_printf.h conversion.c base_system_conversion.c helper.c specifiers.h
OBJS = $(SRCS:.c=.o)

NAME = ft_printf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(NAME)

fclean:clean
	rm -rf $(OBJ)

.PHONY all clean clean