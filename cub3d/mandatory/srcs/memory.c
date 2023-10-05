/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inunez-g <inunez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:08:11 by inunez-g          #+#    #+#             */
/*   Updated: 2023/09/26 11:26:51 by inunez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

static void	*ft_memset(void *b, int c, size_t len)
{
	while (len)
		*(unsigned char *)(b + --len) = (unsigned char)c;
	return ((char *)b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;

	dest = malloc(size * count);
	if (!dest)
		return (NULL);
	ft_memset(dest, 0, size * count);
	return (dest);
}
