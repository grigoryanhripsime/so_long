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

void add_to_coins(t_coins **coins, t_position position)
{
    t_coins *new;
    t_coins *tmp;

    new = malloc(sizeof(t_coins));
    if (!new)
        return ;
    new -> coin = position;
    new -> collected = 0;
    new -> next = NULL;
    if (!*coins)
        *coins = new;
    else
    {
        tmp = *coins;
        while (tmp -> next)
            tmp = tmp -> next;
        tmp -> next = new;
    }
}

t_coins *get_coins(char **map)
{
    t_coins *coins;
    t_position position;
    int i;
    int j;

    i = 0;
    coins = NULL;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'C')
            {
                position.x = i;
                position.y = j;
                add_to_coins(&coins, position);
            }
            j++;
        }
        i++;
    }
    return (coins);
}
