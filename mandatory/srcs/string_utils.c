/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:08:24 by inunez-g          #+#    #+#             */
/*   Updated: 2023/10/16 13:20:29 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

/*
 * Concatenates two strings to create a new one.
 * Parameteres:
 *     s1: the first string
 *     s2: the second string
 * Return:
 *     final_str: a new allocated string cointaining the concatenated result of
 *                s1 and s2.
 *     
 */
char	*ft_strjoin( char const *s1, char const *s2 )
{
	char	*final_str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	final_str = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	i = 0;
	j = 0;
	if (!final_str)
		return (0);
	while (s1[i] != '\0')
		final_str[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
	{
		final_str[j] = s2[i];
		j++;
		i++;
	}
	final_str[j] = '\0';
	return (final_str);
}

/*
 * Extracts a substring from a string startting at index and with a specific
 * length.
 * Parameters:
 *     s: the source string
 *     start: the starting index for the substring
 *     len: the length of the substring
 * Return:
 *     final_str: the newly allocated string containing the extracted
 *                substring.
 *     NULL if memory allocation fails, s is NULL, or len is 0.
 */
char	*ft_substr( char const *s, int start, int len )
{
	char	*final_str;
	int		i;
	int		j;
	int		reallen;
	int		ft;

	i = start;
	j = 0;
	if (!s || !len)
		return (0);
	if (ft_strlen(s) < (size_t)(start + len))
		reallen = (ft_strlen(s) - start);
	else
		reallen = len;
	if (ft_strlen(s) < (size_t)start)
		reallen = 0;
	final_str = (char *)ft_calloc((reallen + 1), (sizeof(char)));
	if (!final_str)
		return (0);
	ft = ft_strlen(s);
	while (i < ft && j < reallen)
		final_str[j++] = s[i++];
	final_str[j] = '\0';
	return (final_str);
}

/*
 * Duplicates a given string 'str' and allocates it with malloc().
 * Parameters:
 *     str: the source string to duplicate
 * Return:
 *     dest: a newly allocated string containing a copy of str.
 *     Return NULL if memory allocation fails
 */
char	*ft_strdup( const char *str )
{
	char	*dest;
	int		i;

	if (!str)
		return (NULL);
	i = -1;
	dest = (char *)ft_calloc((ft_strlen(str) + 1), sizeof(char));
	if (!dest)
		return (NULL);
	while (str[++i])
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}

/*
 * Counts the number of strings in a two-dimensional array and returns
 * that count.
 * Parameters:
 *     str: a pointer to a two-dimensional array of strings
 * Return:
 *     i: the number of the strings in the array
 *     0: is str is NULL
 */
int	ft_2dstrlen(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return(i);
}

/*
 * Removes leading and trailing characters specified in 'set' from the input
 * string 'str' and returns a new dinamically allocated string containing
 * the trimmed result.
 * Parameters:
 *     str:  the input string to trim
 *     set: a string containing  characters to be trimmed
 * Return:
 *     The string containing the trimmed result
 *     NULL if 'str' or 'set' is NULL, or if memory
 */
char	*ft_strtrim(const char *str, char const *set)
{
	size_t	end;

	if (!str || !set)
		return (NULL);
	while (*str != '\0' && ft_strchr(set, *str))
		str++;
	end = ft_strlen(str) - 1;
	while (end && ft_strchr(set, str[end]))
		end--;
	return (ft_substr(str, 0, end + 1));
}