#include "so_long.h"

void error_exit(char *error_message)
{
    int i;

    i = 0;
    while (error_message[i])
        write(2, &error_message[i++], 1);
    exit(1);
}