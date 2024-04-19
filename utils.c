#include "so_long.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
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

	if (!map || !*map || map[start.x] < 0 || start.x >= column || start.y < 0 || start.y >= ft_strlen(map[0]))
		return ;
	c = map[start.x][start.y];
	if (c == 'C' || c == 'E' || c == 'P')
		map[start.x][start.y] = 0;
	if (map[start.x][start.y] != to_fill)
		return ;
	map[start.x][start.y] = 'F';
	fill(map, start.x + 1, (t_position){})
}

char **flood_fill(t_map *map, t_position start)
{
	char **map1;

	map1 = get_map(map);
	int column = 0;
	while (map1[column])
		column++;
	fill(map1, start, column, 0);

}
