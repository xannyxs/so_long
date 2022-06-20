/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_mlx_put_texture.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 22:24:44 by xander        #+#    #+#                 */
/*   Updated: 2022/06/20 22:28:59 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_put_texture(mlx_image_t *screen, mlx_texture_t *texture, int offset_x, int offset_y)
{
	int	x;
	int	y;

	y = 0;
	while (y <= 50)
	{
		x = 0;
		while (x <= 50)
		{
			if (my_mlx_color(texture, x, y) != 0)
				my_mlx_put_pixel(screen, x + offset_x, y + offset_y, \
					my_mlx_color(texture, x, y));
			x++;
		}
		y++;
	}
}
