#include "so_long.h"

void add_to_map(t_map **map, char *str)
{
	t_map *new;
	t_map *temp;

	new = malloc(sizeof(t_map));
	if (!new)
		return ;
	new -> line = str;
	new -> next = NULL;
	temp = *map;
	if (!*map)
	{
		*map = new;
		new -> prev = NULL;
	}
	else
	{
		while (temp -> next)
			temp = temp -> next;
		temp -> next = new;
		new -> prev = temp;
	}
}

t_map *get_map_struct(int fd)
{
    char *next_line;
	t_map *map = NULL;

    while (1)
    {
        next_line = get_next_line(fd);
		if (!next_line)
			break ;
		add_to_map(&map, next_line);
    }
	return (map);
}


