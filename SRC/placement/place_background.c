/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   place_background.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/18 19:58:56 by xander        #+#    #+#                 */
/*   Updated: 2022/06/27 11:51:51 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42/MLX42.h"

#define GRASS "IMG/XPM42/grass.xpm42"

void	place_background(t_vars *vars)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (vars->map_data.world_map[y])
	{
		mlx_draw_texture(vars->screen, &vars->texture.grass->texture, \
			x * 50, y * 50);
		x++;
		if (x >= vars->map_data.width)
		{
			y++;
			x = 0;
		}
	}
}
