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

t_map *get_map(int fd)
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

void trimming_map_start(t_map **map)
{
	t_map *tmp;
	t_map *next;

	tmp = *map;
	while (tmp)
	{
		tmp -> line = ft_strtrim(tmp -> line, " \f\n\r\t\v");
		if (!ft_strlen(tmp -> line))
		{
			next = tmp -> next;
			free(tmp -> line);
			free(tmp);
			tmp = next;
			tmp -> prev = NULL;
		}
		else
			break ;
	}
	(*map) = tmp;
}

void trimming_map_end(t_map **map)
{
	t_map *tmp;
	t_map *prev;

	tmp = *map;
	while (tmp && tmp -> next)
		tmp = tmp -> next;
	while (tmp && tmp -> prev)
	{
		tmp -> line = ft_strtrim(tmp -> line, " \f\n\r\t\v");
		if (!ft_strlen(tmp -> line))
		{
			prev = tmp -> prev;
			free(tmp -> line);
			free(tmp);
			tmp = prev;
			tmp -> next = NULL;
		}
		else
			break ;
	}
}

void trimming_lines(t_map **map)
{
	t_map *tmp;

	tmp = *map;
	while (tmp)
	{
		tmp -> line = ft_strtrim(tmp -> line, " \f\n\r\t\v");
		if (!ft_strlen(tmp ->line) || ft_isspace((tmp -> line)[0]))
		{
			free_map(*map);
			error_exit("White-space in map!!\n");
		}
		tmp = tmp -> next;
	}
}