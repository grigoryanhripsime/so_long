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

t_game *valid_map(t_map **map)
{
	t_game *game;

	valid_chars(map);
	check_borders(map);
	valid_start_end(map);
	game = malloc(sizeof(t_game));
	if (!game)
	{
		free_map(*map);
		error_exit("Malloc error!\n");
	}
	game -> map = *map;
	game -> start = get_start(*map);
	game -> exit = get_exit(*map);
	game -> coins = get_coins(*map);
	printf("Start point: x: %d, y: %d\n", game->start.x, game->start.y);
	printf("End point: x: %d, y: %d\n", game->exit.x, game->exit.y);
	print_coins(game -> coins);
	return (game);
}
