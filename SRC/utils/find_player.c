/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_player.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/18 23:08:35 by xander        #+#    #+#                 */
/*   Updated: 2022/06/18 23:19:23 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_vars *vars, char *world_map[])
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (world_map[y])
	{
		x = 0;
		while (world_map[y][x])
		{
			if (world_map[y][x] == 'P')
			{
				vars->player_x = x;
				vars->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
