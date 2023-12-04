/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:08:11 by inunez-g          #+#    #+#             */
/*   Updated: 2023/11/22 15:01:12 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

/*
 * Setes 'len' bytes of memory at 'b' to the value 'c'. It is often used for
 * initializing memory.
 * Parameters:
 *     b: a pointer to the memory block to fill
 *     c: the value to be set
 *     len: the number of bytes to fill
 * Return:
 *     A pointer to the memory block 'b'
 */
static void	*ft_memset( void *b, int c, size_t len )
{
	while (len)
		*(unsigned char *)(b + --len) = (unsigned char)c;
	return (b);
}

/*
 * Allocates memory for an array of 'count' elements, each of 'size' bytes.
 * Parameters:
 *     count: the number of elements 
 *     size: the size in bytes of each element
 * Return:
 *     dest: a pointer to the allocated memory block
 *     NULL: if memory alocation fails
 */
void	*ft_calloc( size_t count, size_t size )
{
	void	*dest;

	dest = malloc(size * count);
	if (!dest)
		return (NULL);
	ft_memset(dest, 0, size * count);
	return (dest);
}
