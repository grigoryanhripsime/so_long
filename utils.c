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
