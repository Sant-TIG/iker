#include "../incs/cub3d.h"

/*
 * Recorrer la linea
 */
void	get_map_index( t_var *vars )
{
	int	i;
	int	j;

	i = -1;
	while (vars->map[++i])
	{
		j = 0;
		while (ft_isspace(vars->map[i][j]))
			j++;
		if (!ft_isspace(vars->map[i][j]) && ft_isdigit(vars->map[i][j]))
		{
			vars->map_index = i;
			break;
		}
	}
}

void	add_texture( char **texture, t_var *vars)
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

void	check_textures( t_var *vars )
{
	int		i;
	char	**texture;

	i = 0;
	while (i < vars->map_index)
	{
		if (!ft_strcmp(vars->map[i], "\n"))
		{
			i++;
			continue;
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

int	main( int argc, char **argv )
{
	t_var	vars;

	if (argc == 2)
	{
		init(&vars);
		get_map(argv[1], &vars);
		get_map_index(&vars);
		check_textures(&vars);
		print_2dstr(vars.map);
		
		//printf("map = %s\n", vars.map[vars.map_index]);
		//printf("index = %d, %s\n", vars.map_index, vars.map[vars.map_index]);
		return (1);
	}
	process_error(INVALID_PARAMS, &vars);
	return (0);
}