/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:07:42 by inunez-g          #+#    #+#             */
/*   Updated: 2023/09/26 11:36:46 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

static char	*ft_update_temp(char *temp)
{
	int		start;
	char	*real_temp;

	if (!ft_strchr(temp, '\n'))
	{
		free(temp);
		return (0);
	}
	start = ft_strlen(temp) - ft_strlen(ft_strchr(temp, '\n'));
	start += 1;
	real_temp = ft_substr(temp, start, ft_strlen(temp) - start);
	free(temp);
	return (real_temp);
}

static char	*ft_save_line(char *temp)
{
	int		i;
	char	*final_line;

	i = 0;
	if (!temp)
		return (NULL);
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	if (temp[i] == '\0')
	{
		final_line = ft_substr(temp, 0, ft_strlen(temp));
		return (final_line);
	}
	else
	{
		final_line = ft_substr(temp, 0, i + 1);
		return (final_line);
	}
}

static char	*ft_save_temp(char *temp, char *buffer)
{
	char	*temp1;

	if (!(temp))
		temp1 = ft_strdup(buffer);
	else
	{
		temp1 = ft_strjoin(temp, buffer);
		free(temp);
	}
	free(buffer);
	return (temp1);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			nbr_bites;
	static char	*temp;
	char		*line;

	if (fd <= -1)
		return (NULL);
	while (!ft_strchr(temp, '\n'))
	{
		buffer = (char *)ft_calloc(sizeof(char), 2);
		if (!buffer)
			return (NULL);
		nbr_bites = read(fd, buffer, 1);
		if (nbr_bites == -1 || (!nbr_bites && !temp))
		{
			free(buffer);
			return (NULL);
		}
		buffer[nbr_bites] = '\0';
		if (nbr_bites == 0)
			break ;
		temp = ft_save_temp(temp, buffer);
	}
	line = ft_save_line(temp);
	temp = ft_update_temp(temp);
	return (line);
}
