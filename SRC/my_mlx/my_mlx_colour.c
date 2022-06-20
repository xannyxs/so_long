/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_mlx_colour.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 22:19:13 by xander        #+#    #+#                 */
/*   Updated: 2022/06/20 22:21:02 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

UINT	my_mlx_color(mlx_texture_t *img, UINT x, UINT y)
{
	UINT	*pixel;

	if (x >= img->width)
		x = img->width - 1;
	if (y >= img->height)
		y = img->height - 1;
	pixel = (UINT *)(img->pixels + (x + y * img->width) * sizeof(UINT));
	return (*pixel);
}
