#include "so_long.h"

void error_exit(char *error_message)
{
    int i;

    i = 0;
    while (error_message[i])
    {
        write(2, &error_message[i], 1);
        i++;
    }
    exit(1);
}

void free_map_struct(t_map *map)
{
    t_map *tmp;

    while (map)
	{
		tmp = map -> next;
        free(map -> line);
        free(map);
		map = tmp;
	}
}
void free_map(char **map)
{
    int i;

    i = 0;
    while (map[i])
	{
        free(map[i]);
        i++;
	}
    free(map);
}

void free_game(t_game *game)
{
    free_map(game -> map);
    free(game);
}