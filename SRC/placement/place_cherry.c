/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   place_cherry.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/18 22:52:14 by xander        #+#    #+#                 */
/*   Updated: 2022/06/27 11:51:43 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define CHERRY "IMG/XPM42/cherry.xpm42"

void	place_cherry(t_vars *vars)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (vars->map_data.world_map[y])
	{
		if (vars->map_data.world_map[y][x] == 'C')
			my_mlx_put_texture(vars->screen, &vars->texture.cherry->texture, \
				x * 50, y * 50);
		x++;
		if (x >= vars->map_data.width)
		{
			y++;
			x = 0;
		}
	}
}
