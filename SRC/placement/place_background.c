/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   place_background.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/18 19:58:56 by xander        #+#    #+#                 */
/*   Updated: 2022/06/20 21:52:08 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42/MLX42.h"

#define GRASS "IMG/XPM42/grass.xpm42"

//void	draw_sprite(t_vars *vars, xpm_t *sprite, int x, int y)
//{
//	int				img_width;
//	int				img_height;

//	img_width = y;
//	img_height = x;
//	while (img_height != 50)
//	{

//		img_width++;
//		if (img_width == 50)
//		{
//			img_height++;
//			img_width = 0;
//		}
//	}
//}

void	place_background(t_vars *vars)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (vars->map_data.world_map[y])
	{
		mlx_draw_texture(vars->screen, &vars->texture.grass->texture, x * 50, y * 50);
		x++;
		if (x >= vars->map_data.width)
		{
			y++;
			x = 0;
		}
	}
}
