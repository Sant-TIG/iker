#include "../incs/cub3d.h"

/*
 *
 */
static int	check_hex(int nbr)
{
	return (nbr >= 0 && nbr <= 255);
}

/*
 *
 */
static unsigned int rgbToHex(int red, int green, int blue, t_game *game) {
	if (!check_hex(red) || !check_hex(green) || !check_hex(blue))
		process_error(COLOR_ERROR, game);
    return (1  << 24 | (red & 0xFF) << 16) | ((green & 0xFF) << 8) | (blue & 0xFF);
}

unsigned int	get_rgb_texture_aux( char **texture, t_game *game )
{
	int	i;
	int	j;
	int	color[3];
	char	*tmp;

	i = 1;
	j = 0;
	while (texture[i])
	{
		if (j > 2)
			process_error(INVALID_TEXTURE, game);
		if (!ft_strcmp(texture[i], ","))
		{
			i++;
			continue;
		}
		else if (ft_strchr(texture[i], ','))
		{
			tmp = texture[i];
			texture[i] = ft_strtrim(texture[i], ",");
			free(tmp);
		}
		color[j] = ft_atoi(texture[i]);
		j++;
		i++;
	}
	return (rgbToHex(color[0], color[1], color[2], game));
}

unsigned int	get_rgb_texture( char *texture, t_game *game )
{
	char	**rgb_texture;
	int		color[3];
	int		i;

	i = -1;
	rgb_texture = ft_split(texture, ',');
	if (ft_2dstrlen(rgb_texture) != 3)
		process_error(COLOR_ERROR, game);
	while (rgb_texture[++i])
		color[i] = ft_atoi(rgb_texture[i]);
	return (rgbToHex(color[0], color[1], color[2], game));
}
