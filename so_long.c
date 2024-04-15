#include "so_long.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
        error_exit("Too few or many arguments!\n");
    check_map(argv[1]);
}