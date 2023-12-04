#include "../incs/cub3d.h"

void	move_up( t_game *game )
{
	double	moved_x;
	double	moved_y;

	moved_x = game->player_data->pos_x + game->player_data->dir_x * MOVE_SPEED;
	moved_y = game->player_data->pos_y + game->player_data->dir_y * MOVE_SPEED;
	if (game->map[(int)moved_y][(int)game->player_data->pos_x] != '1')
		game->player_data->pos_y = moved_y;
	if (game->map[(int)game->player_data->pos_y][(int)moved_x] != '1')
		game->player_data->pos_x = moved_x;
	mlx_clear_window(game->mlx_data->mlx, game->mlx_data->window);
	raycasting(game);
	mlx_put_image_to_window(game->mlx_data->mlx, game->mlx_data->window, game->mlx_data->img, 0, 0);
}

void	move_back( t_game *game )
{
	double	moved_x;
	double	moved_y;

	moved_x = game->player_data->pos_x - game->player_data->dir_x * MOVE_SPEED;
	moved_y = game->player_data->pos_y - game->player_data->dir_y * MOVE_SPEED;
	if (game->map[(int)moved_y][(int)game->player_data->pos_x] != '1')
		game->player_data->pos_y = moved_y;
	if (game->map[(int)game->player_data->pos_y][(int)moved_x] != '1')
		game->player_data->pos_x = moved_x;
	mlx_clear_window(game->mlx_data->mlx, game->mlx_data->window);
	raycasting(game);
	mlx_put_image_to_window(game->mlx_data->mlx, game->mlx_data->window, game->mlx_data->img, 0, 0);
}

void	move_left( t_game *game )
{
	double	moved_x;
	double	moved_y;

	moved_x = game->player_data->pos_x + game->player_data->dir_y * MOVE_SPEED;
	moved_y = game->player_data->pos_y - game->player_data->dir_x * MOVE_SPEED;
	if (game->map[(int)moved_y][(int)game->player_data->pos_x] != '1')
		game->player_data->pos_y = moved_y;
	if (game->map[(int)game->player_data->pos_y][(int)moved_x] != '1')
		game->player_data->pos_x = moved_x;
	mlx_clear_window(game->mlx_data->mlx, game->mlx_data->window);
	raycasting(game);
	mlx_put_image_to_window(game->mlx_data->mlx, game->mlx_data->window, game->mlx_data->img, 0, 0);
}

void	move_right( t_game *game )
{
	double	moved_x;
	double	moved_y;

	moved_x = game->player_data->pos_x - game->player_data->dir_y * MOVE_SPEED;
	moved_y = game->player_data->pos_y + game->player_data->dir_x * MOVE_SPEED;
	if (game->map[(int)moved_y][(int)game->player_data->pos_x] != '1')
		game->player_data->pos_y = moved_y;
	if (game->map[(int)game->player_data->pos_y][(int)moved_x] != '1')
		game->player_data->pos_x = moved_x;
	mlx_clear_window(game->mlx_data->mlx, game->mlx_data->window);
	raycasting(game);
	mlx_put_image_to_window(game->mlx_data->mlx, game->mlx_data->window, game->mlx_data->img, 0, 0);
}