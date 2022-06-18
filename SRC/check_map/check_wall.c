/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_wall.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/16 15:28:38 by xander        #+#    #+#                 */
/*   Updated: 2022/06/18 19:24:58 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

#include <stdio.h>

#define WALL '1'

static int	loop_through_line(char *map_line, char object)
{
	unsigned int	x;

	x = 0;
	while (map_line[x])
	{
		if (map_line[x] != object)
			return (ERROR);
		x++;
	}
	return (SUCCES);
}

int	check_wall(char *world_map[])
{
	unsigned int	y;

	y = 1;
	if (loop_through_line(world_map[0], WALL))
		return (ERROR);
	while (world_map[y])
	{
		if (world_map[y][0] != WALL)
		{
			printf("%c\n", world_map[y][0]);
			return (ERROR);
		}
		else if (world_map[y][ft_strlen(world_map[y]) - 1] != WALL)
			return (ERROR);
		y++;
	}
	if (loop_through_line(world_map[y - 1], WALL))
		return (ERROR);
	return (SUCCES);
}
