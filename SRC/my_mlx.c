/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_mlx.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 14:51:55 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/29 12:34:50 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	MY_MLX lib, because MLX cannot make working code.
	Pixel_put will place the pixel on the image.
	Colour_put will find the right colour of the XPM image.
*/

void	my_mlx_pixel_put(t_img *img, int x, int y, int colour)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

unsigned int	my_mlx_colour_put(t_img *img, int x, int y)
{
	char			*dst;
	unsigned int	colour;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	colour = *(unsigned int *)dst;
	return (colour);
}
