/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:14:51 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/29 20:22:43 by hrigrigo         ###   ########.fr       */
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
		while (map1[i][j])
		{
			if (map1[i][j] == 'C' || map1[i][j] == 'E')
				return (0);
			j++;
		}
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
	if (!check_start_end_coins(map1))
	{
		free_map_struct(map);
		free_map(map1);
		error_exit("Invalid map!\n");
	}
	start = get_position(map1, 'P');
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
