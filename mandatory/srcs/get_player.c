#include "../incs/cub3d.h"

static void set_player_direction( char direction, t_game *game )
{
	if (direction == 'N')
	{
		game->player_data->dir_y = -1;
		game->player_data->plane_x = 0.66;
	}
	else if (direction == 'S')
	{
		game->player_data->dir_y = 1;
		game->player_data->plane_x = -0.66;
	}
	else if (direction == 'E')
	{
		game->player_data->dir_x = 1;
		game->player_data->plane_y = 0.66;
	}
	else if (direction == 'W')
	{
		game->player_data->dir_x = -1;
		game->player_data->plane_y = -0.66;
	}
}

void    get_player( int i, int j, char direction, t_game *game )
{
    game->player_data->found = 1;
	game->player_data->pos_x = i + 0.5;
	game->player_data->pos_y = j + 0.5;
    set_player_direction(direction, game);
}

/*
 *
 */
void	check_player( t_game *game, int j, int i, char direction )
{
	if (game->player_data->found == 1)
		process_error(REPEATED_PLAYER, game);		
	else
		get_player(i, j, direction, game);
}