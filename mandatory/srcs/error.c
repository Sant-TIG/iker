/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:07:54 by inunez-g          #+#    #+#             */
/*   Updated: 2023/11/22 15:31:05 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"
#include "../incs/colors.h"
#include <errno.h>

static void	print_map_usage( void )
{
	printf(YELLOW "Map usage: the map must be enclosed by walls and can \
only contain the following characters: '0' '1' 'N' 'S' 'W' 'E' ' '.\n" RESET);
}

/*
 * Prints a program usage message, indicating how to use it correctly.
 */
static void	print_usage( void )
{
	printf(YELLOW "Usage: ./cub3d <file_name>.cub\n" RESET);
}

/*
 * Prints error messages to the console and, it it is necessary, executes
 * the print_usage() function.
 */
static void	print_error( char *error, void (*f)(void) )
{
	printf(RED "%s\n" RESET, error);
	if (f)
		(*f)();
}

/*
 * Handles different types of errors and takes appropiate actions.
 * Parameters:
 *     type: the error code to be processed
 */
void	process_error( int type, t_game *game )
{
	if (type == INVALID_EXTENSION)
		print_error("cub3d: error: invalid extension", print_usage);
	else if (type == INVALID_FILE)
		print_error("cub3d: error: invalid file", NULL);
	else if (type == INVALID_TEXTURE)
		print_error("cub3d: error: invalid texture", NULL);
	else if (type == INVALID_PARAMS)
		print_error("cub3d: error: invalid paramaters", print_usage);
	else if (type == INVALID_MAP)
		print_error("cub3d: error: invalid map", print_map_usage);
	else if (type == MALLOC_ERROR)
		print_error("cub3d: error: error allocating memory with malloc(3)", NULL);
	else if (type == COLOR_ERROR)
		print_error("cub3d: error: invalid color", NULL);
	else if (type == NL_MAP_ERROR)
		print_error("cub3d: error: the map cannot be split with line breaks.", NULL);
	else if (type == OPEN_ERROR)
		print_error("cub3d: error: error opening the file.", print_usage);
	else if (type == READ_ERROR)
		print_error("cub3d: error: error reading the file.", NULL);
	else if (type == PLAYER_NOT_FOUND)
		print_error("cub3d: error: player not found in map.", NULL);
	else if (type == REPEATED_PLAYER)
		print_error("cub3d: error: player repeated in map.", NULL);
	else if (type == MISSING_TEXTURE)
		print_error("cub3d: error: missing texture.", NULL);
	else if (type == INVALID_XPM)
		print_error("cub3d: error: error loading xpm file.", NULL);
	general_free(game);
	exit(1);
}
