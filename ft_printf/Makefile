CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c conversion.c base_system_conversion.c helper.c
OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS) $(NAME)

fclean: clean
		rm -rf $(NMAE) $(OBJ)
	
re: fclean all

.PHONY all clean clean re