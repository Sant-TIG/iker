#include "../incs/cub3d.h"

static int	get_file_len( int fd, t_game *game )
{
	int		len;
	int		i;
	int		j;
	char	*buffer;

	len = 0;
	i = 0;
	j = 0;
	while (i == j)
	{
		i++;
		buffer = (char *)ft_calloc(i, sizeof(char));
		if (!buffer)
			process_error(MALLOC_ERROR, game);
		j = read(fd, buffer, i);
		if (j == -1)
			process_error(READ_ERROR, game);
		len += j;
		free(buffer);
	}
	return (len);
}

char	*read_file( char *filename, t_game *game )
{
	int		file_len;
	int		fd;
	char	*content;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		process_error(OPEN_ERROR, game);
	file_len = get_file_len(fd, game);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		process_error(OPEN_ERROR, game);
	if (file_len <= 0)
		return (NULL);
	content = (char *)ft_calloc(file_len + 1, sizeof(char));
	if (!content)
		return (NULL);
	if (read(fd, content, file_len) == -1)
		process_error(READ_ERROR, game);
	content[file_len] = '\0';
	close(fd);
	return (content);
}