#include "so_long.h"

int key_press(int keycode, t_game *game)
{
	int line_len;
	int column_len;

	line_len = line_count(game -> map);
	column_len = ft_strlen(game -> map[0]);
	if (keycode == 53)
    {
		mlx_destroy_window(game -> mlx, game -> window);
        free_game(game);
        exit(0);
    }
	if (keycode == 0) //A
		move_left(game);
	if (keycode == 2) //D
		move_right(game, line_len);
	if (keycode == 13) //W
		move_top(game);
	if (keycode == 1) //S
		move_bottom(game, column_len);
	return (0);
}

void move_left(t_game *game)
{
	t_position player;

	player = game -> player_position;
	game -> map[game->exit_position.x][game->exit_position.y] = 'E';
	if (player.y - 1 > 0)
	{
		if (game -> map[player.x][player.y - 1] == '1')
			return ;
		if (game -> map[player.x][player.y - 1] == 'E')
		{
			if (!look_for_coins(game -> map))
			{
				mlx_destroy_window(game -> mlx, game -> window);
				free_game(game);
				write(1, "You won!\n", 9);
				exit(0);
			}
		}
		game -> map[player.x][player.y] = '0';
		game -> map[player.x][player.y - 1] = 'P';
		(game -> player_position.y)--;
	}
}

void move_right(t_game *game, int line_len)
{
	t_position player;

	player = game -> player_position;
	game -> map[game -> exit_position.x][game -> exit_position.y] = 'E';
	if (player.y + 1 <= line_len)
	{
		if (game -> map[player.x][player.y + 1] == '1')
			return ;
		if (game -> map[player.x][player.y + 1] == 'E')
		{
			if (!look_for_coins(game -> map))
			{
				mlx_destroy_window(game -> mlx, game -> window);
				free_game(game);
				write(1, "You won!\n", 9);
				exit(0);
			}
		}
		game -> map[player.x][player.y] = '0';
		game -> map[player.x][player.y + 1] = 'P';
		(game -> player_position.y)++;
	}
}

void move_top(t_game *game)
{
	t_position player;

	player = game -> player_position;
	game -> map[game -> exit_position.x][game -> exit_position.y] = 'E';
	if (player.x - 1 > 0)
	{
		if (game -> map[player.x - 1][player.y] == '1')
			return ;
		if (game -> map[player.x - 1][player.y] == 'E')
		{
			if (!look_for_coins(game -> map))
			{
				mlx_destroy_window(game -> mlx, game -> window);
				free_game(game);
				write(1, "You won!\n", 9);
				exit(0);
			}
		}
		game -> map[player.x][player.y] = '0';
		game -> map[player.x - 1][player.y] = 'P';
		(game -> player_position.x)--;
	}
}

void move_bottom(t_game *game, int column_len)
{
	t_position player;

	player = game -> player_position;
	game -> map[game -> exit_position.x][game -> exit_position.y] = 'E';
	if (player.x + 1 < column_len)
	{
		if (game -> map[player.x + 1][player.y] == '1')
			return ;
		if (game -> map[player.x + 1][player.y] == 'E')
		{
			if (!look_for_coins(game -> map))
			{
				mlx_destroy_window(game -> mlx, game -> window);
				free_game(game);
				write(1, "You won!\n", 9);
				exit(0);
			}
		}
		game -> map[player.x][player.y] = '0';
		game -> map[player.x + 1][player.y] = 'P';
		(game -> player_position.x)++;
	}
}
