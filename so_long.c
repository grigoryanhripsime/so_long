#include "so_long.h"

void print_map(t_map *map)
{
	while (map)
	{
		printf("%s\n", map ->line);
		map = map -> next;
	}
}

int main(int argc, char *argv[])
{
	int fd;
	t_map *map;

    if (argc != 2)
    {
        error_exit("Too few or many arguments!\n");
    }
        
	fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        error_exit("Couldn't open file!\n");
    }
    map = get_map(fd);
    trimming_map_start(&map);
    trimming_map_end(&map);
    trimming_lines(&map);
    valid_map(&map);
    free_map(map);
}
