#include "../incs/cub3d.h"

/*
 *
 */
static int check_top( int i, int j, char **map )
{
	return (i > 0 && (int)ft_strlen(map[i - 1]) > j && 
			validate_char(map[i - 1][j]));
}

/*
 *
 */
static int check_bottom( int i, int j, char **map )
{
	return (i != ft_2dstrlen(map) - 1 && 
			(int)ft_strlen(map[i + 1]) > j) &&  
			validate_char(map[i + 1][j]);
}

/*
 *
 */
static char *check_right( int i, int j, char **map )
{
	return (validate_char(map[i][j + 1]));
}

/*
 *
 */
static int check_left( int i, int j, char **map )
{
	return (j != 0 && validate_char(map[i][j - 1]));
}

/*
 *
 */
int	check_cross( int i, int j, char **map )
{
	return (check_top(i, j, map) && 
			check_bottom(i, j, map) && 
			check_left(i, j, map) && 
			check_right(i, j, map));
}