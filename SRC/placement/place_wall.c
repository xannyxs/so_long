/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   place_wall.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/18 22:43:05 by xander        #+#    #+#                 */
/*   Updated: 2022/06/27 11:51:39 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define WALL "IMG/XPM42/wall.xpm42"

void	place_wall(t_vars *vars)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (vars->map_data.world_map[y])
	{
		if (vars->map_data.world_map[y][x] == '1')
			mlx_draw_texture(vars->screen, &vars->texture.wall->texture, \
				x * 50, y * 50);
		x++;
		if (x >= vars->map_data.width)
		{
			y++;
			x = 0;
		}
	}
}
