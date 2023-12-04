#include "../incs/cub3d.h"

/*
 *
 */
int	check_complete_map( char *file_content )
{
	int	i;

	i = 0;
	while (file_content[i])
	{
		while (ft_isspace(file_content[i]))
			i++;
		if (ft_isdigit(file_content[i]))
		{
			while (file_content[i])
			{
				if ((file_content[i] == '\n' && file_content[i + 1] == '\n') || 
					(file_content[i] == '\n' && !file_content[i + 1]))
					return (0);
				i++;
			}
		}
		else
		{
			while (file_content[i] && file_content[i] != '\n')
				i++;
		}
	}
	return (1);
}

/*
 * This function compares the file's extension to the expected extension
 * and process an error if they do not match.
 * Parameters:
 *     file: filename to check
 *     extension: the expectedd file extension
 *     vars: a pointer to a t_var structure representing program state.
 */
void	check_extension( char *file, char *extension, t_game *game )
{
	char	*file_extension;

	if (!file || !extension)
		process_error(INVALID_EXTENSION, game);
	file_extension = ft_strrchr(file, '.');
	if (ft_strcmp(extension, file_extension))
		process_error(INVALID_EXTENSION, game);
}


void	check_map( t_game *game )
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (ft_strchr("NSEW", game->map[i][j]))
				check_player(game, i, j, game->map[i][j]);
			else if (game->map[i][j] == '0')
				check_content(i , j, game);
			else if (!ft_strchr("1 ", game->map[i][j]))
				process_error(INVALID_MAP, game);
		}
	}
	if (game->player_data->found == 0)
		process_error(PLAYER_NOT_FOUND, game);
}