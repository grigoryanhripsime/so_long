#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line.h"

//errors.c
void error_exit(char *error_message);


//validation.c
void check_map(char *file);

//ft_split.c
int	ft_strlen(char *s);
int	ft_words_count(char *s);
char	**ft_split(char const *s);

//utils.c
int	ft_isspace(char c);

#endif