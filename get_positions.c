/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:15:45 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/25 19:19:24 by hrigrigo         ###   ########.fr       */
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

t_position	get_start(char **map)
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
			if (map[i][j] == 'P')
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

t_position	get_exit(char **map)
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
			if (map[i][j] == 'E')
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
	game = malloc(sizeof(t_game));
	if (!game)
	{
		free_map_struct(map);
		error_exit("Malloc error!\n");
	}
	game -> map = map1;
	game -> player_position = get_start(map1);
	game -> exit_position = get_exit(map1);
	game -> counter = 0;
	free_map_struct(map);
	if (game -> player_position.x == -1 || game -> player_position.y == -1
		|| game -> exit_position.x == -1 || game -> exit_position.y == -1)
	{
		free_game(game);
		error_exit("Needs to be 1 start and 1 end point!\n");
	}
	return (game);
}
