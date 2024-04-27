/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:16:23 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/27 19:58:02 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	look_for_coins(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	valid_chars(t_map **map)
{
	int		i;
	char	*line;
	t_map	*tmp;

	tmp = *map;
	while (tmp)
	{
		line = tmp -> line;
		if (!line)
			return ;
		i = 0;
		while (line[i] && (line[i] == '1' || line[i] == '0' || line[i] == 'C'
				|| line[i] == 'E' || line[i] == 'P' || line[i] == 'M'))
			i++;
		if (line[i])
		{
			free_map_struct(*map);
			error_exit("Not valid character\n");
		}
		tmp = tmp -> next;
	}
}

void	check_borders(t_map **map)
{
	t_map	*tmp;
	int		i;
	int		line_len;

	tmp = *map;
	line_len = ft_strlen(tmp -> line);
	while (tmp)
	{
		i = 0;
		if (ft_strlen(tmp -> line) != line_len || !((tmp -> line)[0] == '1'
			&& (tmp -> line)[line_len - 1] == '1'))
		{
			free_map_struct(*map);
			error_exit("Invalid border\n");
		}
		while ((!tmp -> prev || !tmp -> next) && (tmp -> line)[i])
		{
			if ((tmp -> line)[i++] != '1')
			{
				free_map_struct(*map);
				error_exit("Invalid border\n");
			}
		}
		tmp = tmp -> next;
	}
}

void	valid_map(t_map **map)
{
	if (!map || ! *map)
	{
		error_exit("Empty map\n");
	}
	trimming_map_start(map);
	trimming_map_end(map);
	trimming_lines(map);
	if (!map || !*map)
		error_exit("Invalid map\n");
	valid_chars(map);
	check_borders(map);
	flood_fill(*map);
}
