/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:07:54 by inunez-g          #+#    #+#             */
/*   Updated: 2023/09/26 11:35:35 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"
#include "../incs/colors.h"
#include <errno.h>

static void	print_usage( void )
{
	printf(YELLOW "Usage: ./cub3d <file_name>.cub\n" RESET);
}

static void	print_error(char	*error, void (*f)(void))
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
void	process_error(int type, t_var *vars)
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
		print_error("cub3d: error: invalid map", NULL);
	else if (type == MALLOC_ERROR)
		print_error("cub3d: error: error allocating memory with malloc(3)", NULL);
	general_free(vars);
	exit(1);
}
