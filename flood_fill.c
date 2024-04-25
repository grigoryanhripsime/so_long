/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:14:51 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/25 19:20:29 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **map, t_position start, int column, char to_fill)
{
	char	c;

	if (!map || !*map || start.x < 0 || start.x >= column
		|| start.y < 0 || start.y >= ft_strlen(map[0]))
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

static int	check_for_unreachable(char **map1)
{
	int	i;
	int	j;

	i = 0;
	while (map1[i])
	{
		j = 0;
		while (map1[i][j] && map1[i][j] == 'C')
			return (0);
		i++;
	}
	return (1);
}

void	flood_fill(t_map *map)
{
	char		**map1;
	t_position	start;
	int			column;

	map1 = get_map(map);
	if (!look_for_coins(map1))
	{
		free_map_struct(map);
		free_map(map1);
		error_exit("There is no collectable!\n");
	}
	start = get_start(map1);
	column = 0;
	while (map1[column])
		column++;
	fill(map1, start, column, '0');
	if (!check_for_unreachable(map1))
	{
		free_map_struct(map);
		free_map(map1);
		error_exit("There is an unreachable point!\n");
	}
	free_map(map1);
}
