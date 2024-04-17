#include "so_long.h"

t_position get_start(t_map *map)
{
    t_position position;
    int i;
    int j;

    i = 0;
    while (map)
    {
        j = 0;
        while (map -> line[j])
        {
            if (map -> line[j] == 'P')
            {
                position.x = i;
                position.y = j;
            }
            j++;
        }
        i++;
        map = map -> next;
    }
    return (position);
}

t_position get_exit(t_map *map)
{
    t_position position;
    int i;
    int j;

    i = 0;
    while (map)
    {
        j = 0;
        while (map -> line[j])
        {
            if (map -> line[j] == 'E')
            {
                position.x = i;
                position.y = j;
            }
            j++;
        }
        i++;
        map = map -> next;
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

t_coins *get_coins(t_map *map)
{
    t_coins *coins;
    t_position position;
    int i;
    int j;

    i = 0;
    coins = NULL;
    while (map)
    {
        j = 0;
        while (map -> line[j])
        {
            if (map -> line[j] == 'C')
            {
                position.x = i;
                position.y = j;
                add_to_coins(&coins, position);
            }
            j++;
        }
        i++;
        map = map -> next;
    }
    return (coins);
}
