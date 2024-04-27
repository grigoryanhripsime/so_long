/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:16:08 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/27 17:00:23 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	int		fd;
	t_map	*map;
	t_game	*game;

	if (argc != 2)
		error_exit("Too few or many arguments!\n");
	check_extention(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_exit("Couldn't open file!\n");
	map = get_map_struct(fd);
	valid_map(&map);
	printf("__%d\n", __LINE__);
	game = getting_positions(map);
	start_mlx(game);
	free_game(game);
	system("leaks so_long");
}
