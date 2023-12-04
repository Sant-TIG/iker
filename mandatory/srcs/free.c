/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:07:51 by inunez-g          #+#    #+#             */
/*   Updated: 2023/11/22 14:37:01 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

/*
 *
 */
void	free_2dstr( char **str )
{
	int		i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

static void	free_textures_data( t_game *game )
{
	if (game->textures_data->no)
		free(game->textures_data->no);
	if (game->textures_data->so)
		free(game->textures_data->so);
	if (game->textures_data->ea)
		free(game->textures_data->ea);
	if (game->textures_data->we)
		free(game->textures_data->we);
}

/*
 *
 */
void	general_free( t_game *game )
{
	if (game->player_data)
		free(game->player_data);
	if (game->textures_data)
		free_textures_data(game);
	if (game->mlx_data)
		free(game->mlx_data);
	if (game->map)
		free_2dstr(game->map);
	if (game->textures)
		free_2dstr(game->textures);
}
