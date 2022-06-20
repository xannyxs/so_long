/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_mlx_pixel_put.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 22:21:28 by xander        #+#    #+#                 */
/*   Updated: 2022/06/20 22:22:31 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_put_pixel(mlx_image_t *img, UINT x, UINT y, UINT color)
{
	UINT	*pixel;

	if (x >= img->width || y >= img->height)
		return ;
	pixel = (UINT *)&img->pixels[(x + y * img->width) * sizeof(UINT)];
	*pixel = color;
}
