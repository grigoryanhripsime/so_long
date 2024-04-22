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
	game -> player = get_start(map1);
	game -> exit = get_exit(map1);
	game -> coins = get_coins(map1);
	free_map(map);
    return (game);
}

int funkcia(int keycode, t_game *game)
{
	(void) game;
	if (keycode == 53)
		mlx_destroy_window(game -> mlx, game -> window);
	return (0);

}

void start_mlx(t_game *game)
{
	int lines;
	int columns;
	void *mlx;
	void *window;

	mlx = mlx_init();
	if (!mlx)
	{
		free_game(game);
		error_exit("mlx_init failed!\n");
	}
	lines = line_count(game -> map);
	columns = ft_strlen(game -> map[0]);
	window = mlx_new_window(mlx, columns * 60, lines * 60, "so_long");
	mlx_hook(window, 2, 0, &funkcia, game);
	//mlx_loop_hook(mlx, ban, game);
	mlx_loop(mlx);

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
	start_mlx(game);
    free_game(game);
}
