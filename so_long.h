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

typedef struct s_coins
{
	t_position coin;
	int collected;
	struct s_coins *next;
} t_coins;

typedef struct s_game //malloced
{
	char **map; //malloced
	t_position start; //P
	t_position exit_position; //E
	t_position player_position;
	t_coins *coins; //C  malloced
	void *mlx; 
	void *window;
	void *exit;
	void *player;
	void *coin;
	void *free_space;
	void *border;
	int *pixel_width;
	int *pixel_height;
} t_game;

//errors.c
void error_exit(char *error_message);
void free_map(t_map *map);
void free_game(t_game *game);
void free_map1(char **map);

//so_long.c
void print_map(t_map *map);
void print_coins(t_coins *coins);

//validation.c
void valid_chars(t_map **map);
void check_borders(t_map **map);
void valid_start_end(t_map **map);
void valid_map(t_map **map);
char **get_map(t_map *map);

//getting_map.c
void add_to_map(t_map **map, char *str);
t_map *get_map_struct(int fd);
void trimming_map_start(t_map **map);
void trimming_map_end(t_map **map);
void trimming_lines(t_map **map);

//ft_strtrim.c
char	*ft_strtrim(char *s1, char *set);

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
t_position get_start(char **map);
t_position get_exit(char **map);
t_coins *get_coins(char **map);

//set_mlx.c
int key_press(int keycode, t_game *game);
void start_mlx(t_game *game);
void locate_textures(t_game *game);

#endif