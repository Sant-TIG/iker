/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:08:08 by inunez-g          #+#    #+#             */
/*   Updated: 2023/11/24 18:14:24 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void	print_player( t_game *game )
{
	printf("\nPOSICIONES\n%f y %f\n", game->player_data->pos_x, game->player_data->pos_y);
	printf("\nDIRECCION\n%f  y %f\n", game->player_data->dir_x, game->player_data->dir_y);
	printf("\nPLANE\n%f y %f\n", game->player_data->plane_x, game->player_data->plane_y);
}

void	print_img( t_img *img )
{
	printf("\nDIRECCIONES\n, %p %p\n", img->img, img->addr);
	printf("\nIMGS FEATURES\n%d %d %d %d %d\n", img->bits_per_pixel, img->endian, img->line_length, img->width, img->height);
}

/*
 * 
 */
int	main( int argc, char **argv )
{
	t_game	game;
	void	*pepe;
	pepe = NULL;

	if (argc == 2)
	{
		init(&game);
		game.mlx_data->mlx = mlx_init();
		get_map(argv[1], &game);
		get_textures(&game);
		print_2dstr(game.map);
		print_2dstr(game.textures);
		print_player(&game);
		print_img(game.textures_data->no);
		print_img(game.textures_data->so);
		print_img(game.textures_data->we);
		print_img(game.textures_data->ea);
		printf("c = %u\n", game.textures_data->c);
		printf("f = %u\n", game.textures_data->f);
		process_game(&game);
		return (1);
	}
	process_error(INVALID_PARAMS, &game);
	return (0);
}