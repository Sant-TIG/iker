/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristinasansegundo <cristinasansegundo@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:07:57 by inunez-g          #+#    #+#             */
/*   Updated: 2023/11/17 18:22:18 by cristinasan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

/*
 * Checks if a character is a white space character.
 * Parameters:
 *     c: the character to check
 * Return:
 *     1: if 'c' is a white space  character
 *     0: if it is not.
 */
int ft_isspace( int c )
{
    return((c >= 9 && c <= 13) || c == 32);
}

/*
 * Check is a character is a digit.
 * Parameters:
 *     c: the character to check
 * Return:
 *     1: if 'c' is a digit
 *     0: if it is not.
 */
int ft_isdigit( int  c )
{
    return (c >= 48 && c <= 57);
}
