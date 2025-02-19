/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrigrigo <hrigrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:16:04 by hrigrigo          #+#    #+#             */
/*   Updated: 2024/04/29 20:39:14 by hrigrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player(t_game *game)
{
	if (game -> c && game -> c == 'l')
		mlx_put_image_to_window(game->mlx, game->window,
			game -> player1, game->player_position.y * 60,
			game->player_position.x * 60);
	else if (game -> c && game -> c == 'r')
		mlx_put_image_to_window(game->mlx, game->window,
			game -> player, game->player_position.y * 60,
			game->player_position.x * 60);
}

void	locate_textures(t_game *game)
{
	int		i;
	int		j;
	char	*counter;

	i = 0;
	while (game -> map[i])
	{
		j = 0;
		while (game -> map[i][j])
		{
			set_image(game, i, j);
			j++;
		}
		i++;
	}
	set_player(game);
	counter = ft_itoa(game -> counter);
	mlx_string_put(game->mlx, game->window, 0, 0, 0x0000FF00, "Counter");
	mlx_string_put(game->mlx, game->window, 80, 0, 0x0000FF00, counter);
	free(counter);
}

void	set_image(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->window, game -> player,
		game->player_position.y * 60, game->player_position.x * 60);
	if (game -> map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game -> border, j * 60, i * 60);
	if (game -> map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game -> exit, j * 60, i * 60);
	if (game -> map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			anim(game), j * 60, i * 60);
	if (game -> map[i][j] == 'M')
		mlx_put_image_to_window(game->mlx, game->window,
			game -> monster, j * 60, i * 60);
}

void	set_textures(t_game *game)
{
	int	*height;
	int	*width;

	height = malloc(sizeof(int));
	*(height) = 60;
	width = malloc(sizeof(int));
	*(width) = 60;
	game -> player = mlx_xpm_file_to_image(game -> mlx,
			"textures/player.xpm", width, height);
	game -> player1 = mlx_xpm_file_to_image(game -> mlx,
			"textures/player1.xpm", width, height);
	game -> border = mlx_xpm_file_to_image(game -> mlx,
			"textures/border.xpm", width, height);
	game -> exit = mlx_xpm_file_to_image(game -> mlx,
			"textures/exit.xpm", width, height);
	game -> coin = mlx_xpm_file_to_image(game -> mlx,
			"textures/coin.xpm", width, height);
	game -> coin1 = mlx_xpm_file_to_image(game -> mlx,
			"textures/coin1.xpm", width, height);
	game -> monster = mlx_xpm_file_to_image(game -> mlx,
			"textures/monster.xpm", width, height);
	free(height);
	free(width);
}

void	start_mlx(t_game *game)
{
	int	lines;
	int	columns;

	game -> mlx = mlx_init();
	if (!game -> mlx)
	{
		free_game(game);
		error_exit("mlx_init failed!\n");
	}
	lines = line_count(game -> map);
	columns = ft_strlen(game -> map[0]);
	game -> window = mlx_new_window(game -> mlx,
			columns * 60, lines * 60, "so_long");
	set_textures(game);
	locate_textures(game);
	mlx_hook(game -> window, 2, 0, &key_press, game);
	mlx_hook(game -> window, 17, 0, &mouse_press, game);
	mlx_loop_hook(game -> mlx, &clean_draw_map, game);
	mlx_loop(game -> mlx);
}
