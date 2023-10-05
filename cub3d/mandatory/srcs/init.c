/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:08:02 by inunez-g          #+#    #+#             */
/*   Updated: 2023/09/26 11:38:52 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

/*
 * Initializes the player structure. After initializes it resets the value of
 * its coordenates.
 */
static void init_player(t_var *vars)
{
    vars->player = (t_player *)ft_calloc(1, sizeof(t_player));
    if (!vars->player)
        process_error(MALLOC_ERROR, vars);
    vars->player->x = -1;
    vars->player->y = -1;
}

/*
 * Initializes the textures structure.
 */
static void init_textures(t_var *vars)
{
    vars->textures = (t_textures *)ft_calloc(1, sizeof(t_textures));
    if (!vars->player)
        process_error(MALLOC_ERROR, vars);
}

/*
 * Initializes all the program's variables and structures.
 */
void    init(t_var  *vars)
{
    vars->fd = -1;
    vars->map = NULL;
    vars->lines = 0;
    vars->map_index = -1;
    vars->lst_map = NULL;
    init_textures(vars);
    init_player(vars);
}
