/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_collectable.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/18 19:03:39 by xander        #+#    #+#                 */
/*   Updated: 2022/06/18 19:03:47 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collectables(char *world_map[])
{
	unsigned int	x;
	unsigned int	y;

	y = 1;
	while (world_map[y])
	{
		x = 0;
		while (world_map[y][x])
		{
			if (world_map[y][x] == 'C')
				return (SUCCES);
			x++;
		}
		y++;
	}
	return (ERROR);
}
