/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/18 19:09:55 by xander        #+#    #+#                 */
/*   Updated: 2022/06/18 19:10:59 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error.h"

static void	get_map_size(t_map *map_data)
{
	int	x;
	int	y;

	y = 0;
	map_data->width = 0;
	while (map_data->world_map[y] != NULL)
	{
		x = 0;
		while (map_data->world_map[y][x] != '\0')
			x++;
		if ((int)map_data->width < x - 1)
			map_data->width = x - 1;
		y++;
	}
	map_data->height = y - 1;
}

int	check_map(t_map *map_data)
{
	get_map_size(map_data);
	if (check_unknown(map_data->world_map))
	{
		non_fatal_error(UNKNOWN_CHAR);
		return (ERROR);
	}
	if (check_wall(map_data->world_map))
	{
		non_fatal_error(MISSING_WALL);
		return (ERROR);
	}
	if (check_player(map_data->world_map))
	{
		non_fatal_error(MISSING_PLAYER);
		return (ERROR);
	}
	if (check_collectables(map_data->world_map) || \
		check_exit(map_data->world_map))
	{
		non_fatal_error(MISSING_MISCS);
		return (ERROR);
	}

	return (SUCCES);
}
