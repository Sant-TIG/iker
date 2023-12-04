/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:07:45 by inunez-g          #+#    #+#             */
/*   Updated: 2023/11/22 19:01:21 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

static char	**save_textures( t_game *game )
{
	char	**textures;
	int	i;

	i = 0;
	while (i < game->map_index)
		i++;
	textures = (char **)ft_calloc(i + 1, sizeof(char *));
	if (!textures)
		process_error(MALLOC_ERROR, game);
	i = -1;
	while (++i < game->map_index)
		textures[i] = ft_strdup(game->content[i]);
	textures[i] = NULL;
	return (textures);
}

static char	**save_map( t_game *game )
{
	int	i;
	int	j;
	char	**map;

	i = game->map_index;
	while (game->content[i])
		i++;
	map = (char **)malloc(sizeof(char *) * (i + 1));
	if (!map)
		process_error(MALLOC_ERROR, game);
	i = game->map_index - 1;
	j = -1;
	while (game->content[++i])
		map[++j] = ft_strdup(game->content[i]);
	map[++j] = NULL;
	return (map);
}

/*
 * Determines the index of the map. Finds the index based on the first
 * non-whitespace, digit character in the two-dimension array.
 * Parameters:
 *     game: a pointer to a t_game structure representing program state.  
 */
static void	get_map_index( t_game *game )
{
	int	i;
	int	j;

	i = -1;
	while (game->content[++i])
	{
		j = 0;
		while (ft_isspace(game->content[i][j]))
			j++;
		if (!ft_isspace(game->content[i][j]) && ft_isdigit(game->content[i][j]))
		{
			game->map_index = i;
			break ;
		}
	}
}

/*
 * Read and parses the map from a file. Checks the file extension, opens the
 * file, reads the map, and determines the starting index for parsing it.
 * Parameters:
 *     game: a pointer to a t_game structure representing program state.
 */
void	get_map( char *file, t_game *game )
{
	char	*file_content;

	check_extension(file, ".cub", game);
	file_content = read_file(file, game);
	if (!check_complete_map(file_content))
		process_error(NL_MAP_ERROR, game);
	game->content = ft_split(file_content, '\n');
	free(file_content);
	get_map_index(game);
	game->textures = save_textures(game);
	game->map = save_map(game);
	check_map(game);

}
