/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:08:27 by inunez-g          #+#    #+#             */
/*   Updated: 2023/10/04 12:40:56 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

/*
 * Calculates the length of a string excluding the null terminator character.
 * Parameters:
 *     str: pointer to the string in which the length will be calculated
 * Return:
 *     i: the length of the string
 */
size_t	ft_strlen( const char *str )
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

/*
 * Searches for the last ocurrence of the character 'c' in the string pointed
 * to by 'str'.
 * Parameters:
 *     str: pointer to the string in which the search will be performed
 *     c: the character to search for in the string
 * Return:
 *     A pointer to the last found character
 *     NULL if the character is not found
 */

char	*ft_strrchr(const char	*str, int c)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	if ((unsigned char)c == '\0')
		return ((char *)str + i);
	while (i--)
	{
		if ((unsigned char)*(str + i) == (unsigned char)c)
			return ((char *)str + i);
	}
	return (NULL);
}

/*
 * Searches for the first ocurrence of the character 'c' in the string pointed
 * to by 'str'.
 * Parameters:
 *     str: pointer to the string in which the search will be performed
 *     c: the character to search for in the string
 * Return:
 *     A pointer to the last found character
 *     NULL if the character is not found
 */

char	*ft_strchr(const char	*str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (*(str + i))
	{
		if ((unsigned char)*(str + i) == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

/*
 * Compares two strings.
 * Parameters:
 *     str1: pointer to the first string for comparison
 *     str2: pointer to the second string for comparison
 * Return:
 *     0 is tr1 is equal to str2
 *     A negative value if str1 is less than str2
 *     A positive value is str1 is greater than str2
 */
int	ft_strcmp( const char *str1, const char *str2 )
{
	if (!str1 || !str2)
		return (0);
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/*
 * Searches for the first occurrence of a substring within a string.
 * Parameters:
 *     haystack: pointer to the string the substring will be searched
 *     needle: pointer to the substring to be found
 * Return:
 *     A pointer to the begining of the first match of the substring.
 *     NULL if it is not found 
 */
char	*ft_strstr(const char *haystack, const char *needle)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	if (!needle || !haystack)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	while (haystack[++i])
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
	}
	return (NULL);
}
