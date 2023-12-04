#include "../incs/cub3d.h"

/*
 *
 */
char	*validate_char( int c )
{
	return (ft_strchr("01NSEW", c));
}

/*
 *
 */
static int	check_corners( int i, int j, char **map )
{
	return (validate_char(map[i + 1][j - 1]) && 
			validate_char(map[i + 1][j + 1]) && 
			validate_char(map[i - 1][j - 1]) &&
			validate_char(map[i - 1][j + 1]));
}

/*
 *
 */
void	check_content( int i, int j, t_game *game )
{
	if (!check_cross(i, j, game->map) || !check_corners(i, j, game->map))
		process_error(INVALID_MAP, game);
}