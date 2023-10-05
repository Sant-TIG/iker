#include "../incs/cub3d.h"

static void	add_texture( char **texture, t_var *vars)
{
	if (!ft_strcmp(texture[0], "NO"))
		vars->textures->no = ft_strdup(texture[1]);
	else if (!ft_strcmp(texture[0], "SO"))
		vars->textures->so = ft_strdup(texture[1]);
	else if (!ft_strcmp(texture[0], "EA"))
		vars->textures->ea = ft_strdup(texture[1]);
	else if (!ft_strcmp(texture[0], "WE"))
		vars->textures->we = ft_strdup(texture[1]);
	else if (!ft_strcmp(texture[0], "C"))
		vars->textures->c = ft_strdup(texture[1]);
	else if (!ft_strcmp(texture[0], "F"))
		vars->textures->f = ft_strdup(texture[1]);
}

static void	check_texture( t_var *vars, char **texture )
{
	int	len;
	int	i;

	len = ft_2dstrlen(vars->textures);
	i = 0;
	while (i < len)
	{
		if (!ft_strstr(TEXTURES, texture[i][0]))
			process_error(INVALID_TEXTURE, vars);	
	}
}

void	get_textures( t_var *vars )
{
	int		i;
	char	**texture;

	i = 0;
	while (i < vars->map_index)
	{
		if (!ft_strcmp(vars->map[i], "\n"))
		{
			i++;
			continue ;
		}
		texture = split_textures(vars->map[i], vars);

		print_2dstr(texture);
		if (!texture)
			process_error(INVALID_TEXTURE, vars);
		add_texture(texture, vars);
		free_2dstr(texture);
		texture = NULL;
		i++;
	}
}