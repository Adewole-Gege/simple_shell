CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
SRCS = main.c builtin.c env_builtins.c environ.c errors.c getline.c \
       helper.c input_helpers.c linkedlist.c locate.c proc_file_comm.c \
       split.c str_funcs1.c str_funcs2.c
OBJS = $(SRCS:.c=.o)
TARGET = hsh

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
