#include "so_long.h"

void locate_textures(t_game *game)
{
    int i;
    int j;
	char *counter;

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
	counter = ft_itoa(game -> counter);
	mlx_string_put(game->mlx, game->window, 0, 0, 0x0000FF00, "Counter");
	mlx_string_put(game->mlx, game->window, 80, 0, 0x0000FF00, counter);
	free(counter);
}

void set_image(t_game *game, int i, int j)
{
	if (game -> map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game -> border, j * 60, i * 60);
	if (game -> map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game -> player, j * 60, i * 60);
	if (game -> map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game -> exit, j * 60, i * 60);
	if (game -> map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game -> coin, j * 60, i * 60);
	if (game -> map[i][j] == 'M')
		mlx_put_image_to_window(game->mlx, game->window, game -> monster, j * 60, i * 60);
}

void set_textures(t_game *game, int columns, int lines)
{
	int *height;
	int *width;
	
    height = malloc(sizeof(int));
    *(height) = 60;
    width = malloc(sizeof(int));
    *(width) = 60;
	game -> window = mlx_new_window(game -> mlx, columns * 60, lines * 60, "so_long");
    game -> player = mlx_xpm_file_to_image(game -> mlx, "textures/player.xpm", width, height);
    game -> border = mlx_xpm_file_to_image(game -> mlx, "textures/border.xpm", width, height);
    game -> exit = mlx_xpm_file_to_image(game -> mlx, "textures/exit.xpm", width, height);
    game -> coin = mlx_xpm_file_to_image(game -> mlx, "textures/coin.xpm", width, height);
	game -> monster = mlx_xpm_file_to_image(game -> mlx, "textures/monster.xpm", width, height);
	free(height);
    free(width);
}

void start_mlx(t_game *game)
{
	int lines;
	int columns;

	game -> mlx = mlx_init();
	if (!game -> mlx)
	{
		free_game(game);
		error_exit("mlx_init failed!\n");
	}
	lines = line_count(game -> map);
	columns = ft_strlen(game -> map[0]);
	set_textures(game, columns, lines);
    locate_textures(game);
    mlx_hook(game -> window, 2, 0, &key_press, game);
    mlx_loop_hook(game -> mlx, &clean_draw_map, game);
	mlx_loop(game -> mlx);
}
