/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinasansegundo <cristinasansegundo@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:08:21 by inunez-g          #+#    #+#             */
/*   Updated: 2023/11/16 16:34:11 by cristinasan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"
#include <fcntl.h>

/*
 * Counts the number of non-empty values separated by whitespace in the input
 * string.
 * Parameters:
 *     str:
 * Return:
 *     The number of non-empty values in the string
 *     -1 if str is NULL
 */
static int	count_values( char *str )
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		while (ft_isspace(str[i]) && str[i])
			i++;
		if (!ft_isspace(str[i]) && str[i])
		{
			len++;
			while (!ft_isspace(str[i]) && str[i])
				i++;
		}
	}
	return (len);
}

/*
 * Duplicates a portion of the string 's' from index 'start' to 'finish'.
 * Parameters:
 *     s: the source string
 *     start: the starting index of the substring
 *     finish: the ending index of the substring
 * Returns:
 *     - A newly allocated string containing the duplicated substring.
 *     - Returns NULL if memory allocation fails
 */
static char	*splitdup(const char *s, size_t start, size_t finish, t_game *game)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *)ft_calloc((finish - start + 1), sizeof(char));
	if (!dest)
		process_error(MALLOC_ERROR, game);
	while (start < finish)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}

/*
 * Splits a string into an array of substrings. These substrings are the content
 * of str that is between white space characters.
 * Parameters:
 *     str: the input string to split
 *     dst: an array where the resulting substring will be stored
 * Return:
 *     An array of substrings
 *     NULL if memory alocation fails
 */
char	**fill_textures( char *str, char **dst, t_game *game )
{
	int	i;
	int	start;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]) && str[i])
			i++;
		if (!str[i])
			break ;
		start = i;
		while (!ft_isspace(str[i]) && str[i])
			i++;
		dst[j] = splitdup(str, start, i, game);
		j++;
	}
	dst[j] = NULL;
	return (dst);
}

/*
 * Splits a string into an array of substrings. First it counts how many
 * strings the two-dimensional array will consist of. Then allocates
 * the array with calloc and fills them with fill_textures.
 */
char	**split_textures(char	*str, t_game	*game)
{
	int		len;
	char	**dst;

	len = count_values(str);
	if (!str)
		return (NULL);
	dst = (char **)ft_calloc(len + 1, sizeof(char *));
	if (!dst)
		process_error(MALLOC_ERROR, game);
	dst = fill_textures(str, dst, game);
	return (dst);
}
