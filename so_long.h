#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line.h"

typedef struct s_map 
{
	char *line;
	struct s_map *next;
}	t_map;

//errors.c
void error_exit(char *error_message);


//validation.c
t_map *get_map(int fd);

//ft_strtrim.c
char	*ft_strtrim(char *s1, char *set);

//ft_split.c
int	ft_strlen(char *s);
int	ft_words_count(char *s);
char	**ft_split(char const *s);

//utils.c
int	ft_isspace(char c);

#endif