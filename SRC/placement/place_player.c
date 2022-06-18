///* ************************************************************************** */
///*                                                                            */
///*                                                        ::::::::            */
///*   locate_obj.c                                       :+:    :+:            */
///*                                                     +:+                    */
///*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
///*                                                   +#+                      */
///*   Created: 2022/01/24 21:41:03 by xvoorvaa      #+#    #+#                 */
///*   Updated: 2022/04/29 12:34:50 by xander        ########   odam.nl         */
///*                                                                            */
///* ************************************************************************** */

#include "so_long.h"

#define PLAYER "IMG/XPM42/player.xpm42"

void	place_player(t_vars *vars)
{
	unsigned int	x;
	unsigned int	y;
	xpm_t			*sprite;

	x = 0;
	y = 0;
	sprite = mlx_load_xpm42(PLAYER);
	vars->screen = mlx_texture_to_image(vars->mlx, &sprite->texture);
	while (vars->map_data.world_map[y])
	{
		if (vars->map_data.world_map[y][x] == 'P')
			mlx_image_to_window(vars->mlx, vars->screen, x * 50, y * 50);
		x++;
		if (x >= vars->map_data.width)
		{
			y++;
			x = 0;
		}
	}
}

