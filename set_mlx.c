#include "so_long.h"

int look_for_coins(char **map)
{
    int i;
    int j;

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

int key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
    {
		mlx_destroy_window(game -> mlx, game -> window);
        free_game(game);
        exit(0);
    }
	return (0);
}


int key_press_loop(int keycode, t_game *game)
{
    printf("hello %d\n", keycode);
    if (keycode == 0x7a)
    {
        printf("__%d\n", __LINE__);
        game -> map[game -> exit_position.x][game -> exit_position.y] = 'E';
        if (game -> player_position.x - 1 > 0)
        {
            if (game -> map[game -> player_position.x][game -> player_position.y] == '1')
                return (0);
            if (game -> map[game -> player_position.x][game -> player_position.y] == 'E')
            {
                if (!look_for_coins(game -> map))
                {
                    mlx_destroy_window(game -> mlx, game -> window);
                    free_game(game);
                    write(1, "You won!\n", 9);
                    exit(0);
                }
            }
            else
            {
                game -> map[game -> player_position.x][game -> player_position.y] = '0';
                game -> map[game -> player_position.x - 1][game -> player_position.y] = 'P';
                (game -> player_position.x)--;
            }
        }
        printf("__%d\n", __LINE__);

        mlx_clear_window(game -> mlx, game -> window);
        locate_textures(game);
    }
	return (0);
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
    printf("__%d\n", __LINE__);
	lines = line_count(game -> map);
	columns = ft_strlen(game -> map[0]);
    game -> pixel_height = malloc(sizeof(int));
    *(game -> pixel_height) = 60;
    game -> pixel_width = malloc(sizeof(int));
    *(game -> pixel_width) = 60;
	game -> window = mlx_new_window(game -> mlx, columns * 60, lines * 60, "so_long");
    game -> player = mlx_xpm_file_to_image(game -> mlx, "textures/player.xpm", game -> pixel_width, game -> pixel_height);
    game -> border = mlx_xpm_file_to_image(game -> mlx, "textures/border.xpm", game -> pixel_width, game -> pixel_height);
    game -> exit = mlx_xpm_file_to_image(game -> mlx, "textures/exit.xpm", game -> pixel_width, game -> pixel_height);
    game -> coin = mlx_xpm_file_to_image(game -> mlx, "textures/coin.xpm", game -> pixel_width, game -> pixel_height);
    free(game -> pixel_height);
    free(game -> pixel_width);
    locate_textures(game);
    mlx_key_hook(game -> window, &key_press, game);
    printf("__%d\n", __LINE__);
    mlx_loop_hook(game -> mlx, &key_press_loop, game);
	// mlx_hook(game -> window, 2, 0, &key_press, game); //this will work only for macos
	mlx_loop(game -> mlx);
}

void locate_textures(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game -> map[i])
    {
        j = 0;
        while (game -> map[i][j])
        {
            if (game -> map[i][j] == '1')
                mlx_put_image_to_window(game -> mlx,game -> window, game -> border, j * 60, i * 60);
            if (game -> map[i][j] == 'P')
                mlx_put_image_to_window(game -> mlx,game -> window, game -> player, j * 60, i * 60);
            if (game -> map[i][j] == 'E')
                mlx_put_image_to_window(game -> mlx,game -> window, game -> exit, j * 60, i * 60);
            if (game -> map[i][j] == 'C')
                mlx_put_image_to_window(game -> mlx,game -> window, game -> coin, j * 60, i * 60);
            j++;
        }
        i++;
    }
}