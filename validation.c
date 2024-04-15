#include "so_long.h"

void valid_chars(char *line)
{
	int i;

	if (!line)
		return ;
	i = 0;
	while (line[i] && (line[i] == '1' || line[i] == '0' || line[i] == 'C' || line[i] == 'E' || line[i] == 'P'))
		i++;
	if (line[i])
	{
		free(line);
		error_exit("Not valid character\n");
	}
}
void add_to_list(t_map **map, char *str)
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
		*map = new;
	else
	{
		while (temp -> next)
			temp = temp -> next;
		temp -> next = new;
	}
}
t_map *get_map(int fd)
{
    char *next_line;
	t_map *map = NULL;

    while (1)
    {
        next_line = get_next_line(fd);
		printf("%d\n", __LINE__);
		if (!next_line)
			break ;
		add_to_list(&map, next_line);
		//free(next_line);
    }
	return (map);
}

