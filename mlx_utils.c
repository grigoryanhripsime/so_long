/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:15:55 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/27 16:33:30 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clean_draw_map(t_game *game)
{
	mlx_clear_window(game -> mlx, game -> window);
	locate_textures(game);
	return (0);
}

void	check_exit(t_game *game)
{
	if (!look_for_coins(game -> map))
	{
		mlx_destroy_window(game -> mlx, game -> window);
		free_game(game);
		write(1, "You won :)\n", 11);
		exit(0);
	}
}

void	check_monster(t_game *game)
{
	mlx_destroy_window(game -> mlx, game -> window);
	write(1, "You lost :(\n", 12);
	free_game(game);
	exit(0);
}

void	*anim(t_game *game)
{
	static int	i;

	if (i < 20)
	{
		i++;
		return (game -> coin);
	}
	if (i < 60)
	{
		i++;
		return (game -> coin1);
	}
	i = 0;
	return (game -> coin);
}
