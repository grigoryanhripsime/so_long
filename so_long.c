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

t_game *getting_started(t_map *map)
{
    t_game *game;
    char **map1;

    map1 = get_map(map);

    game = malloc(sizeof(t_game));
	if (!game)
	{
		free_map(map);
		error_exit("Malloc error!\n");
	}
	game -> map = map1;
	game -> start = get_start(map1);
	game -> exit = get_exit(map1);
	game -> coins = get_coins(map1);
	printf("Start point: x: %d, y: %d\n", game->start.x, game->start.y);
	printf("End point: x: %d, y: %d\n", game->exit.x, game->exit.y);
	print_coins(game -> coins);
    return (game);
}

int main(int argc, char *argv[])
{
	int fd;
	t_map *map;
    t_game *game;

    if (argc != 2)
    {    error_exit("Too few or many arguments!\n");}
	fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {    error_exit("Couldn't open file!\n");}
    map = get_map_struct(fd);
    valid_map(&map);
    game = getting_started(map);
    free_game(game);
}
