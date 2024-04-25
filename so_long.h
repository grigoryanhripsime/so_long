#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "get_next_line.h"
# include <mlx.h>

typedef struct s_map
{
	struct s_map *prev;
	char *line;
	struct s_map *next;
}	t_map;

typedef struct s_position
{
	int x;
	int y;
} t_position;

typedef struct s_game //malloced
{
	char **map; //malloced
	t_position exit_position; //E
	t_position player_position; //P
	void *mlx; 
	void *window;
	void *exit;
	void *player;
	void *coin;
	void *monster;
	void *free_space;
	void *border;
	int counter;
} t_game;

//errors.c
void error_exit(char *error_message);
void free_map_struct(t_map *map);
void free_game(t_game *game);
void free_map(char **map);

//so_long.c
void print_map(char **map);
void check_extention(char *str);

//validation.c
void valid_chars(t_map **map);
void check_borders(t_map **map);
void valid_map(t_map **map);
char **get_map(t_map *map);
int look_for_coins(char **map);

//getting_map.c
void add_to_map(t_map **map, char *str);
t_map *get_map_struct(int fd);


//trimming.c
char	*ft_strtrim(char *s1, char *set);
void trimming_map_start(t_map **map);
void trimming_map_end(t_map **map);
void trimming_lines(t_map **map);

//ft_split.c
int	ft_strlen(char *s);
int	ft_words_count(char *s);
char	**ft_split(char const *s);

//utils.c
int	ft_isspace(char c);
int map_len(t_map *map);
char	*ft_strchr(const char *s);
void flood_fill(t_map *map);
int line_count(char **map);

//get_positions.c
char **get_map(t_map *map);
t_position get_start(char **map);
t_position get_exit(char **map);
t_game *getting_positions(t_map *map);

//set_mlx.c
void start_mlx(t_game *game);
void locate_textures(t_game *game);
void set_textures(t_game *game, int columns, int lines);
void set_image(t_game *game, int i, int j);

//mlx_utils.c
int clean_draw_map(t_game *game);
void check_exit(t_game *game);
void check_monster(t_game *game);

//move.c
int key_press(int keycode, t_game *game);
void move_left(t_game *game);
void move_right(t_game *game, int line_len);
void move_top(t_game *game);
void move_bottom(t_game *game, int column_len);

//ft_itoa.c
char	*ft_itoa(int n);

#endif