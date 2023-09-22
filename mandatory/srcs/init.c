#include "../incs/cub3d.h"


void    init(t_var *vars)
{
    vars->textures = (t_textures *)malloc(sizeof(t_textures));
    vars->textures->so = NULL;
    vars->textures->ea = NULL;
    vars->textures->we = NULL;
    vars->textures->f = NULL;
    vars->textures->c = NULL;
    vars->textures->filled = 0;
	vars->lst_map = NULL;
    vars->lines = 0;
}