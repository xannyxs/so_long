/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_exit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/18 19:04:02 by xander        #+#    #+#                 */
/*   Updated: 2022/06/18 19:04:17 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define EXIT 'E'

int	check_exit(char *world_map[])
{
	unsigned int	x;
	unsigned int	y;

	y = 1;
	while (world_map[y])
	{
		x = 0;
		while (world_map[y][x])
		{
			if (world_map[y][x] == EXIT)
				return (SUCCES);
			x++;
		}
		y++;
	}
	return (ERROR);
}
