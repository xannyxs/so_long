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

	x = 0;
	y = 0;
	while (vars->map_data.world_map[y])
	{
		if (vars->map_data.world_map[y][x] == 'P')
			my_mlx_put_texture(vars->screen, &vars->texture.player->texture, x * 50, y * 50);
		x++;
		if (x >= vars->map_data.width)
		{
			y++;
			x = 0;
		}
	}
}

