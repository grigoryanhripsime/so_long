#include "so_long.h"

void valid_chars(t_map **map)
{
	int i;
	char *line;
	t_map *tmp;

	tmp = *map;
	while (tmp)
	{
		line = tmp -> line;
		if (!line)
			return ;
		i = 0;
		while (line[i] && (line[i] == '1' || line[i] == '0' || line[i] == 'C' || line[i] == 'E' || line[i] == 'P'))
			i++;
		if (line[i])
		{
			free_map(*map);
			error_exit("Not valid character\n");
		}
		tmp = tmp -> next;
	}
}

void check_borders(t_map **map)
{
	t_map *tmp;
	int i;
	int line_len;

	tmp = *map;
	line_len = ft_strlen(tmp -> line);
	while (tmp)
	{
		i = 0;
		if (ft_strlen(tmp -> line) != line_len || !((tmp -> line)[0] == '1' && (tmp -> line)[line_len - 1] == '1'))
		{
			free_map(*map);
			error_exit("Invalid border\n");
		}
		while ((!tmp -> prev || !tmp -> next) && (tmp -> line)[i])
		{
			if ((tmp -> line)[i++] != '1')
			{
				free_map(*map);
				error_exit("Invalid border\n");
			}
		}
		tmp = tmp -> next;
	}
}

void valid_start_end(t_map **map)
{
	t_map *tmp;
	int i;
	int start;
	int end;

	tmp = *map;
	start = 0;
	end = 0;
	while (tmp)
	{
		i = 0;
		while ((tmp -> line)[++i])
		{
			if ((tmp -> line)[i - 1] == 'P')
				start++;
			if ((tmp -> line)[i - 1] == 'E')
				end++;
		}
		tmp = tmp -> next;
	}
	if (start != 1 || end != 1)
	{
		free_map(*map);
		error_exit("There needs to be 1 start and 1 end point\n");
	}
}

void valid_map(t_map **map)
{
	valid_chars(map);
	check_borders(map);
	valid_start_end(map);
}