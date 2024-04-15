#include "so_long.h"

void print_map(t_map **map)
{
	t_map *new = *map;
	while (new)
	{
		printf("%s", new ->line);
		new = new -> next;
	}
}

int main(int argc, char *argv[])
{
	int fd;
	t_map *map;

    if (argc != 2)
        error_exit("Too few or many arguments!\n");
	fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        error_exit("Couldn't open file!\n");
	printf("%d\n", __LINE__);
    map = get_map(fd);
	print_map(&map);
}
