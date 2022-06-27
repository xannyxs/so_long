/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   does_collect_exist.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/27 11:13:16 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/27 11:52:43 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdbool.h>

bool	does_collect_exist(char *world_map[])
{
	UINT	x;
	UINT	y;

	y = 0;
	while (world_map[y])
	{
		x = 0;
		while (world_map[y][x])
		{
			if (world_map[y][x] == 'C')
				return (true);
			x++;
		}
		y++;
	}
	return (false);
}
