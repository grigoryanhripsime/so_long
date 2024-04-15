CC = cc

CFLAGS = -Wall -Wextra -Werror -I ./

NAME = so_long

SRCS = so_long.c errors.c ft_split.c validation.c utils.c get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS) Makefile so_long.h
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re bonus