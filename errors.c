#include "so_long.h"

void error_exit(char *error_message)
{
    int i;

    i = 0;
    while (error_message[i])
    {
        //printf("%c", error_message[i]);
        write(2, &error_message[i], 1);
        i++;
    }
    exit(1);
}

void free_map(t_map *map)
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

void free_game(t_game *game)
{
    t_coins *tmp;

    free_map(game -> map);

    while (game -> coins)
    {
        tmp = game -> coins -> next;
        free(game -> coins);
        game -> coins = tmp;
    }
    free(game);
}