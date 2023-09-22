#include "../incs/cub3d.h"

char	*ft_strjoin( char const *s1, char const *s2 )
{
	char	*final_str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	final_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
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
	final_str = (char *)malloc((reallen + 1) * (sizeof(char)));
	if (!final_str)
		return (0);
	ft = ft_strlen(s);
	while (i < ft && j < reallen)
		final_str[j++] = s[i++];
	final_str[j] = '\0';
	return (final_str);
}

char	*ft_strdup( const char *str )
{
	char	*dest;
	int		i;

	if (!str)
		return (NULL);
	i = -1;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dest)
		return (NULL);
	while (str[++i])
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}