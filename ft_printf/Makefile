CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c ft_printf.h conversion.c base_system_conversion.c helper.c specifiers.h
OBJS = $(SRCS:.c=.o)

TARGET = ft_printf

all: $(TARGET)

$TARGET: $(OBJS)
	$(SS) $(CFLAGS) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)