# include "../incs/cub3d.h"

void    right_move( t_game *game )
{
    double  old_dir_x;
    double  old_plane_x;

    old_dir_x = game->player_data->dir_x;
    game->player_data->dir_x = game->player_data->dir_x * cos(-ROT_SPEED) - game->player_data->dir_y * sin(-ROT_SPEED);
    game->player_data->dir_y = old_dir_x * sin(-ROT_SPEED) + game->player_data->dir_y * cos(-ROT_SPEED);
    old_plane_x = game->player_data->plane_x;
    game->player_data->plane_x = game->player_data->plane_x * cos(-ROT_SPEED) - game->player_data->plane_y * sin (-ROT_SPEED);
    game->player_data->plane_y = old_plane_x * sin(-ROT_SPEED) + game->player_data->plane_y * cos(-ROT_SPEED);
	mlx_clear_window(game->mlx_data->mlx, game->mlx_data->window);
	raycasting(game);
	mlx_put_image_to_window(game->mlx_data->mlx, game->mlx_data->window, game->mlx_data->img, 0, 0);

}

void    left_move( t_game *game )
{
    double  old_dir_x;
    double  old_plane_x;

    old_dir_x = game->player_data->dir_x;
    game->player_data->dir_x = game->player_data->dir_x * cos(ROT_SPEED) - game->player_data->dir_y * sin(ROT_SPEED);
    game->player_data->dir_y = old_dir_x * sin(ROT_SPEED) + game->player_data->dir_y * cos(ROT_SPEED);
    old_plane_x = game->player_data->plane_x;
    game->player_data->plane_x = game->player_data->plane_x * cos(ROT_SPEED) - game->player_data->plane_y * sin (ROT_SPEED);
    game->player_data->plane_y = old_plane_x * sin(ROT_SPEED) + game->player_data->plane_y * cos(ROT_SPEED);
  	mlx_clear_window(game->mlx_data->mlx, game->mlx_data->window);
	raycasting(game);
	mlx_put_image_to_window(game->mlx_data->mlx, game->mlx_data->window, game->mlx_data->img, 0, 0);
  
}