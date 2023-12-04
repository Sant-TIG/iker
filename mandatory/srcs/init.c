/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:08:02 by inunez-g          #+#    #+#             */
/*   Updated: 2023/11/24 18:19:17 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

/*
 * Initializes the mlx data structure.
 */
static void init_mlx_data( t_game *game )
{
    game->mlx_data = (t_mlx *)ft_calloc(1, sizeof(t_mlx));
    if (!game->mlx_data)
        process_error(MALLOC_ERROR, game);
    game->mlx_data->mlx = mlx_init();
}

/*
 * Initializes the textures data structure.
 */
static void init_textures_data( t_game *game )
{
    game->textures_data = (t_textures *)ft_calloc(1, sizeof(t_textures));
    if (!game->textures_data)
        process_error(MALLOC_ERROR, game);
    game->textures_data->no = (t_img *)ft_calloc(1, sizeof(t_img));
    if (!game->textures_data->no)
        process_error(MALLOC_ERROR, game);
    game->textures_data->so = (t_img *)ft_calloc(1, sizeof(t_img));
    if (!game->textures_data->so)
        process_error(MALLOC_ERROR, game);
    game->textures_data->ea = (t_img *)ft_calloc(1, sizeof(t_img));
    if (!game->textures_data->ea)
        process_error(MALLOC_ERROR, game);
    game->textures_data->we = (t_img *)ft_calloc(1, sizeof(t_img));
    if (!game->textures_data->we)
        process_error(MALLOC_ERROR, game);
}

/*
 * Initializes the player data structure.
 */
static void init_player_data( t_game *game )
{
    game->player_data = (t_player *)ft_calloc(1, sizeof(t_player));
    if (!game->player_data)
        process_error(MALLOC_ERROR, game);
}

/*
 * Initializes all the program's structures. Before allocating them, it initializes
 * them to NULL so that they can be freed in case the memory allocation fails.
 */
void    init( t_game *game )
{
    game->player_data = NULL;
    game->textures_data = NULL;
    game->mlx_data = NULL;
    game->map = NULL;
    game->textures = NULL;
    game->map_index = 0;
    init_player_data(game);
    init_textures_data(game);
    init_mlx_data(game);
}
