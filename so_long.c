#include "so_long.h"

void print_map(t_map *map)
{
	while (map)
	{
		printf("%s\n", map ->line);
		map = map -> next;
	}
}

void print_coins(t_coins *coins)
{
	while (coins)
	{
		printf("pos: x: %d y: %d  collected: %d\n", coins -> coin.x, coins -> coin.y, coins -> collected);
		coins = coins -> next;
	}
}

int main(int argc, char *argv[])
{
	int fd;
	t_map *map;
    t_game *game;

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
    game = valid_map(&map);
    free_game(game);
}
