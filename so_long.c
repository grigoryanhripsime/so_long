#include "so_long.h"

void print_map(char **map)
{
	int i = 0;
	int j;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
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
	game = getting_positions(map);
	start_mlx(game);
    free_game(game);
}
