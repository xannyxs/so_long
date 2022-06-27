/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   place_exit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/18 22:54:46 by xander        #+#    #+#                 */
/*   Updated: 2022/06/27 11:51:32 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define EXIT "IMG/XPM42/exit.xpm42"

void	place_exit(t_vars *vars)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (vars->map_data.world_map[y])
	{
		if (vars->map_data.world_map[y][x] == 'E')
			my_mlx_put_texture(vars->screen, &vars->texture.exit->texture, \
				x * 50, y * 50);
		x++;
		if (x >= vars->map_data.width)
		{
			y++;
			x = 0;
		}
	}
}
