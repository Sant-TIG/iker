#include "../incs/cub3d.h"

void	lst_to_array(t_var *vars)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = vars->lst_map;
	vars->map = (char **)malloc(sizeof(char *) * (vars->lines + 1));
	if (!vars->map)
		return ;
	while (i < vars->lines)
	{
		vars->map[i] = ft_strdup((char *)tmp->line);
		tmp = tmp->next;
		i++;
	}
	vars->map[vars->lines] = NULL;
}

static void	read_map( t_var	*vars )
{
	char	*line;

	line = get_next_line(vars->fd);
	if (!line)
		process_error(INVALID_FILE, vars);
	while (1)
	{
		if (line == NULL)
			line = get_next_line(vars->fd);
		if (!line)
			break;
		ft_lstadd_back(&vars->lst_map, ft_lstnew(ft_strdup(line)));
		vars->lines +=1;
		ft_free(&line);
	}
	lst_to_array(vars);
}

static void	check_extension( char *file, char *extension, t_var *vars )
{
	char	*file_extension;

	if (!file || !extension)
		process_error(INVALID_EXTENSION, vars);
	file_extension = ft_strrchr(file, '.');
	if (ft_strcmp(extension, file_extension))
		process_error(INVALID_EXTENSION, vars);
}

void	get_map( char *file, t_var *vars )
{
	check_extension(file, ".cub", vars);
	vars->fd = open(file, O_RDONLY);
	if (vars->fd == -1)
		process_error(INVALID_FILE, vars);
	read_map(vars);
	//print_list(vars);
	//print_2dstr(vars->map);
}
