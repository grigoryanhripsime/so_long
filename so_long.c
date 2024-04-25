#include "so_long.h"

void print_map(t_map *map)
{
	while (map)
	{
		printf("%s\n", map ->line);
		map = map -> next;
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
	game -> player_position = get_start(map1);
	game -> exit_position = get_exit(map1);
	free_map(map);
    return (game);
}
void check_extention(char *str)
{
	int len;

	len = ft_strlen(str);
	if (len < 5 || str[len - 4] != '.' || str[len - 3] != 'b' || str[len - 2] != 'e' || str[len - 1] != 'r')
		error_exit("Wrong map name.\n");
}

int main(int argc, char *argv[])
{
	int fd;
	t_map *map;
    t_game *game;

    if (argc != 2)
		error_exit("Too few or many arguments!\n");
	check_extention(argv[1]);
	fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    	error_exit("Couldn't open file!\n");
    map = get_map_struct(fd);
    valid_map(&map);
	game = getting_started(map);
	start_mlx(game);
    free_game(game);
}
