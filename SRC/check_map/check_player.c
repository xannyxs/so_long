/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_player.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/18 19:03:05 by xander        #+#    #+#                 */
/*   Updated: 2022/06/18 19:12:50 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdbool.h>

#define MANY_PLAYERS_ERROR 2

static bool	does_player_already_exist(bool player_exists)
{
	if (player_exists == false)
	{
		player_exists = true;
		return (true);
	}
	return (false);
}

int	check_player(char *world_map[])
{
	unsigned int	x;
	unsigned int	y;
	bool			player_exists;

	x = 0;
	y = 1;
	player_exists = false;
	while (world_map[y])
	{
		while (world_map[y][x])
		{
			if (world_map[y][x] == 'P')
			{
				player_exists = does_player_already_exist(player_exists);
				if (player_exists == false)
					return (MANY_PLAYERS_ERROR);
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (player_exists == true)
		return (SUCCES);
	return (ERROR);
}
