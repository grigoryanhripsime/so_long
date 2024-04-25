#include "so_long.h"

t_position get_start(char **map)
{
    t_position position;
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
            {
                position.x = i;
                position.y = j;
            }
            j++;
        }
        i++;
    }
    return (position);
}

t_position get_exit(char **map)
{
    t_position position;
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'E')
            {
                position.x = i;
                position.y = j;
            }
            j++;
        }
        i++;
    }
    return (position);
}

