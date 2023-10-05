/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:07:45 by inunez-g          #+#    #+#             */
/*   Updated: 2023/10/04 12:37:19 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

/*
 * Determines the index of the map. Finds the index based on the first
 * non-whitespace, digit character in the two-dimension array.
 * Parameters:
 *     vars: a pointer to a t_var structure representing program state.  
 */
static void	get_map_index( t_var *vars )
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
			break ;
		}
	}
}

/*
 * Converts a linked list of strings into a two-dimensional array of characters.
 * Allocates memory using calloc for vars->map and populates it with the lines
 * in the linked list. 
 * 
 * The resulting array is NULL-terminated. If memory allocation fails, it exit
 * the program with the correspongin error.
 * Parameters:
 *     vars: a pointer to a t_var structure representing program state.
 */
static void	lst_to_array(t_var *vars)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = vars->lst_map;
	vars->map = (char **)ft_calloc((vars->lines + 1), sizeof(char *));
	if (!vars->map)
		process_error(MALLOC_ERROR, vars) ;
	while (i < vars->lines)
	{
		vars->map[i] = ft_strdup((char *)tmp->line);
		tmp = tmp->next;
		i++;
	}
	vars->map[vars->lines] = NULL;
}

/*
 * Reads lines from the file using get_next_line(), adds them to the linked
 * list and converts it to an two-dimensional array.
 * Parameters:
 *     vars: a pointer to a t_var structure representing program state.
 */
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
			break ;
		ft_lstadd_back(&vars->lst_map, ft_lstnew(ft_strdup(line)));
		vars->lines += 1;
		ft_free(&line);
	}
	lst_to_array(vars);
}

/*
 * This function compares the file's extension to the expected extension
 * and process an error if they do not match.
 * Parameters:
 *     file: filename to check
 *     extension: the expectedd file extension
 *     vars: a pointer to a t_var structure representing program state.
 */
static void	check_extension( char *file, char *extension, t_var *vars )
{
	char	*file_extension;

	if (!file || !extension)
		process_error(INVALID_EXTENSION, vars);
	file_extension = ft_strrchr(file, '.');
	if (ft_strcmp(extension, file_extension))
		process_error(INVALID_EXTENSION, vars);
}

/*
 * Read and parses the map from a file. Checks the file extension, opens the
 * file, reads the map, and determines the starting index for parsing it.
 * Parameters:
 *     vars: a pointer to a t_var structure representing program state.
 */
void	get_map( char *file, t_var *vars )
{
	check_extension(file, ".cub", vars);
	vars->fd = open(file, O_RDONLY);
	if (vars->fd == -1)
		process_error(INVALID_FILE, vars);
	read_map(vars);
	get_map_index(vars);
}
