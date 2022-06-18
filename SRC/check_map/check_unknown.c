/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_unknown.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/18 19:04:37 by xander        #+#    #+#                 */
/*   Updated: 2022/06/18 19:05:32 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define PLAYER 'P'
#define EXIT 'E'
#define COLLECT 'C'
#define WALL '1'
#define EMPTY '0'

int	check_unknown(char *world_map[])
{
	int	x;
	int	y;

	y = 0;
	while (world_map[y])
	{
		x = 0;
		while (world_map[y][x])
		{
			if (world_map[y][x] != PLAYER &&
				world_map[y][x] != COLLECT &&
				world_map[y][x] != EXIT &&
				world_map[y][x] != WALL &&
				world_map[y][x] != EMPTY)
				return (ERROR);
			x++;
		}
		y++;
	}
	return (SUCCES);
}
