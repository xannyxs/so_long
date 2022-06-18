/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   place_background.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/18 19:58:56 by xander        #+#    #+#                 */
/*   Updated: 2022/06/18 22:39:50 by xander        ########   odam.nl         */
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
	xpm_t			*sprite;

	x = 0;
	y = 0;
	sprite = mlx_load_xpm42(GRASS);
	vars->screen = mlx_texture_to_image(vars->mlx, &sprite->texture);
	while (vars->map_data.world_map[y])
	{
		mlx_image_to_window(vars->mlx, vars->screen, x * 50, y * 50);
		x++;
		if (x >= vars->map_data.width)
		{
			y++;
			x = 0;
		}
	}
}
