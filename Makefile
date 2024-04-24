CC = cc

CFLAGS = -Wall -Wextra -Werror -I ./ -g3 -fsanitize=address

NAME = so_long

SRCS = so_long.c errors.c ft_split.c validation.c utils.c get_next_line.c get_next_line_utils.c ft_strtrim.c getting_map.c get_positions.c set_mlx.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)


$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

# $(NAME): $(OBJS) Makefile so_long.h 
# 	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $@

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re bonus