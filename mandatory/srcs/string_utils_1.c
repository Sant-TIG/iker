#include "../incs/cub3d.h"

/*
 *
 */
int	ft_atoi(const char *str)
{
	int	result;
	ssize_t	sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		result = (*str++ - 48) + (result * 10);
	return (result * sign);
}

/*
 * Counts the number of substrings in a string 's' separated by the character 'c'.
 * Parameters:
 *     s: the string to count substrings in
 *     c: the separator character
 * Return:
 *     count: the number of substrings
 */
static size_t	ft_line_counter(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s == c && *s)
		s++;
	while (*s)
	{
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
		count++;
	}
	return (count);
}

/*
 * Allocates memory for a substring from 'start' to 'finish' in 's' and duplicates it.
 * Parameters:
 *     s: the string where the substring is to be subtracted.
 *     start: the starting index
 *     finish: the ending index
 * Return:
 *     dest: a newly allocated string containing the substring
 *     NULL if memory allocation fails
 */
static char	*ft_splitdup(const char *s, size_t start, size_t finish)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (finish - start + 1));
	if (!dest)
		return (NULL);
	while (start < finish)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}

/*
 * Fills the two-dimensional array allocated before with substrings from 's' using the
 * separator character 'c'.
 * Parameters:
 *     dest: the two-dimensional array to store the substrings
 *     s: the input string to extract substrings from
 *     c: the separator character
 * Return:
 *     dest: the updated array containing the extracted substrings
 */
static char	**ft_fill_split(char **dest, const char *s, char c)
{
	size_t	i;
	size_t	p1;
	size_t	start;

	i = 0;
	p1 = 0;
	start = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
		{
			i++;
			if (s[i] == c || i == ft_strlen(s))
				dest[p1++] = ft_splitdup(s, start, i);
		}
		while (s[i] == c && s[i])
		{
			i++;
			start = i;
		}
	}
	dest[p1] = NULL;
	return (dest);
}

/*
 * Splits a string into an array of substrings using the separator character 'c' and returns
 * them in a dinamically allocated array.
 * Parameters:
 *     s: the string to split
 *     c: the separator character
 * Return:
 *     dest: the string to split
 *     Return NULL if memory allocation fails
 */
char	**ft_split(const char *s, char c)
{
	char	**dest;

	if (!s)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * (ft_line_counter(s, c) + 1));
	if (!dest)
		return (NULL);
	ft_fill_split(dest, s, c);
	return (dest);
}