#include "../incs/cub3d.h"
#include <math.h>

static int	end_game(t_game *game)
{
	mlx_destroy_image(game->mlx_data->mlx, game->textures_data->no->img);
	mlx_destroy_image(game->mlx_data->mlx, game->textures_data->so->img);
	mlx_destroy_image(game->mlx_data->mlx, game->textures_data->ea->img);
	mlx_destroy_image(game->mlx_data->mlx, game->textures_data->we->img);
	mlx_clear_window(game->mlx_data->mlx, game->mlx_data->window);
	mlx_destroy_window(game->mlx_data->mlx, game->mlx_data->window);
	general_free(game);
	exit(0);
}

int	process_keycode(int keycode, t_game *game)
{
	if (keycode == 13)
		move_up(game);
	else if (keycode == 1)
		move_back(game);
	else if (keycode == 0)
		move_left(game);
	else if (keycode == 2)
		move_right(game);
	else if (keycode == 123)
		right_move(game);
	else if (keycode == 124)
		left_move(game);
	else if (keycode == 53)
		end_game(game);
	return (0);
}


void    my_mlx_pixel_put_pp( t_game *game, int x, int y, int color )
{
    char    *dst;

    dst = game->mlx_data->addr + (y * game->mlx_data->line_length + x * (game->mlx_data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void	raycas( t_game *game )
{
	my_mlx_pixel_put_pp(game, 5, 5, 0x00FF0000);
	my_mlx_pixel_put_pp(game, 6, 5, 0x00FF0000);
	my_mlx_pixel_put_pp(game, 7, 5, 0x00FF0000);
	my_mlx_pixel_put_pp(game, 8, 5, 0x00FF0000);
	my_mlx_pixel_put_pp(game, 9, 5, 0x00FF0000);
	my_mlx_pixel_put_pp(game, 10, 5, 0x00FF0000);
	my_mlx_pixel_put_pp(game, 11, 5, 0x00FF0000);
}

void	process_game( t_game *game )
{
	game->mlx_data->window = mlx_new_window(game->mlx_data->mlx, WIDTH, HEIGHT, "cub3d");
	game->mlx_data->img = mlx_new_image(game->mlx_data->mlx, WIDTH, HEIGHT);
	game->mlx_data->addr = mlx_get_data_addr(game->mlx_data->img, &game->mlx_data->bits_per_pixel, &game->mlx_data->line_length, &game->mlx_data->endian);
	raycasting(game);
	mlx_put_image_to_window(game->mlx_data->mlx, game->mlx_data->window, game->mlx_data->img, 0, 0);
	mlx_hook(game->mlx_data->window, 2, 1L << 0, process_keycode, game);
	mlx_hook(game->mlx_data->window, 17, 1L << 17, end_game, game);
	mlx_loop(game->mlx_data->mlx);
}