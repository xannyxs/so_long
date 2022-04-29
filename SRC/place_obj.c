/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   place_obj.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/16 17:03:16 by xander        #+#    #+#                 */
/*   Updated: 2022/01/28 14:30:50 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#define TRANSPARENT (unsigned int) -16777216

void	draw_sprite(t_img *img, t_img *sprite, int x, int y)
{
	int				img_width;
	int				img_height;
	unsigned int	colour;

	img_width = 0;
	img_height = 0;
	while (img_height != 50)
	{
		colour = my_mlx_colour_put(sprite, img_width, img_height);
		if (colour != TRANSPARENT)
			my_mlx_pixel_put(img, img_width + x, img_height + y, \
				my_mlx_colour_put(sprite, img_width, img_height));
		img_width++;
		if (img_width == 50)
		{
			img_height++;
			img_width = 0;
		}
	}
}

void	place_all_objects(t_vars vars, t_node *map)
{
	t_img	img;

	img.img = mlx_new_image(vars.mlx, vars.width * 50, \
		vars.height * 50);
	if (img.img == NULL)
		exit(-1);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_length, &img.endian);
	place_background(&vars, &img, map);
	place_wall(&vars, &img, map);
	place_cherry(&vars, &img, map);
	place_player(&vars, &img, map);
	place_exit(&vars, &img, map);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
}
