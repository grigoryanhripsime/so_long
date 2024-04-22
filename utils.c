#include "so_long.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int line_count(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int map_len(t_map *map)
{
	int len;

	len = 0;
	while (map)
	{
		len++;
		map = map -> next;
	}
	return (len);
}

char	*ft_strchr(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (ft_isspace(s[i]))
			return ((char *) s);
		i++;
	}
	return (0);
}

void fill(char **map, t_position start, int column, char to_fill)
{
	char c;

	if (!map || !*map || start.x < 0 || start.x >= column || start.y < 0 || start.y >= ft_strlen(map[0]))
		return ;
	c = map[start.x][start.y];
	if (c == 'C' || c == 'E' || c == 'P')
		map[start.x][start.y] = '0';
	if (map[start.x][start.y] != to_fill)
		return ;
	map[start.x][start.y] = 'F';
	fill(map, (t_position){start.x - 1, start.y}, column, to_fill);
	fill(map, (t_position){start.x + 1, start.y}, column, to_fill);
	fill(map, (t_position){start.x, start.y - 1}, column, to_fill);
	fill(map, (t_position){start.x, start.y + 1}, column, to_fill);
}

static int check_for_unreachable(char **map1)
{
	int i;
	int j;

	i = 0;
	while (map1[i])
	{
		j = 0;
		while (map1[i][j] && (map1[i][j] == '1' || map1[i][j] == 'F'))
			j++;
		if (map1[i][j])
			return (0);
		i++;
	}
	return (1);
}

void flood_fill(t_map *map)
{
	char **map1;
	t_position start;

	map1 = get_map(map);
	start = get_start(map1);
	int column = 0;
	while (map1[column])
		column++;
	fill(map1, start, column, '0');
	if (!check_for_unreachable(map1))
	{
		free_map(map);
		free_map1(map1);
		error_exit("There is an unreachable point!\n");
	}
	free_map1(map1);
}
