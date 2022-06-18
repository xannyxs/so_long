/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   place_wall.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/18 22:43:05 by xander        #+#    #+#                 */
/*   Updated: 2022/06/18 23:50:02 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define WALL "IMG/XPM42/wall.xpm42"

void	place_wall(t_vars *vars)
{
	unsigned int	x;
	unsigned int	y;
	xpm_t			*sprite;

	x = 0;
	y = 0;
	sprite = mlx_load_xpm42(WALL);
	vars->screen = mlx_texture_to_image(vars->mlx, &sprite->texture);
	while (vars->map_data.world_map[y])
	{
		if (vars->map_data.world_map[y][x] == '1')
			mlx_image_to_window(vars->mlx, vars->screen, x * 50, y * 50);
		x++;
		if (x >= vars->map_data.width)
		{
			y++;
			x = 0;
		}
	}
}
