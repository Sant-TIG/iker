#include "../incs/cub3d.h"

int ft_isspace(int c)
{
    return ((c >= 9 && c <= 13) || c == 32);
}

int ft_isdigit(int c)
{
    return (c >= 48 && c <= 57);
}