/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:15:19 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/27 20:02:07 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *error_message)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	while (error_message[i])
	{
		write(2, &error_message[i], 1);
		i++;
	}
	system("leaks so_long");
	exit(1);
}

void	free_map_struct(t_map *map)
{
	t_map	*tmp;

	while (map)
	{
		tmp = map -> next;
		free(map -> line);
		free(map);
		map = tmp;
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_game(t_game *game)
{
	free_map(game -> map);
	free(game);
}

void	check_extention(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 5 || str[len - 4] != '.' || str[len - 3] != 'b'
		|| str[len - 2] != 'e' || str[len - 1] != 'r')
		error_exit("Wrong map name.\n");
}
