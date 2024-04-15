#include "so_long.h"

void valid_map(int fd)
{
    char *next_line;
    //char *splited_line;

    while (1)
    {
        next_line = get_next_line(fd);
        printf("%s", next_line);
        //splited_line = ft_split(next_line);
        // if (ft_strlen(splited_line))
        //     check_for_valid_map()
    }
}

void check_map(char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        error_exit("Couldn't open file!\n");
    valid_map(fd);
}
