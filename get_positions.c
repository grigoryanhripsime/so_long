/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:15:45 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/29 20:25:57 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(t_map *map)
{
	int		i;
	char	**map1;
	t_map	*next;

	map1 = malloc(sizeof(t_map) * (map_len(map) + 1));
	if (!map1)
	{
		free_map_struct(map);
		error_exit("Error while malloc");
	}
	i = 0;
	while (map)
	{
		map1[i] = ft_strdup(map -> line);
		next = map -> next;
		map = next;
		i++;
	}
	map1[i] = NULL;
	return (map1);
}

void	look_for_start_end(char **map, int *start, int *exit, int *coins)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				(*start)++;
			if (map[i][j] == 'E')
				(*exit)++;
			if (map[i][j] == 'C')
				(*coins)++;
			j++;
		}
		i++;
	}
}

int	check_start_end_coins(char **map)
{
	int	start;
	int	exit;
	int	coins;

	start = 0;
	exit = 0;
	coins = 0;
	look_for_start_end(map, &start, &exit, &coins);
	if (start != 1 || exit != 1 || coins < 1)
		return (0);
	return (1);
}

t_position	get_position(char **map, char c)
{
	t_position	position;
	int			i;
	int			j;

	position.x = -1;
	position.y = -1;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				position.x = i;
				position.y = j;
			}
			j++;
		}
		i++;
	}
	return (position);
}

t_game	*getting_positions(t_map *map)
{
	t_game	*game;
	char	**map1;

	map1 = get_map(map);
	if (!check_start_end_coins(map1))
	{
		free_map_struct(map);
		free_map(map1);
		error_exit("Invalid map!\n");
	}
	game = malloc(sizeof(t_game));
	if (!game)
	{
		free_map(map1);
		free_map_struct(map);
		error_exit("Malloc error!\n");
	}
	game -> map = map1;
	game -> player_position = get_position(map1, 'P');
	game -> exit_position = get_position(map1, 'E');
	game -> counter = 0;
	free_map_struct(map);
	return (game);
}
