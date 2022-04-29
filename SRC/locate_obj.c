/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   locate_obj.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 21:41:03 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/29 12:34:50 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define WALL "IMG/wall.xpm"
#define WALL_INT 1
#define EXIT "IMG/exit.xpm"
#define EXIT_E 'E'
#define PLAYER_P 'P'
#define GRASS "IMG/grass.xpm"
#define GRASS_INT 0
#define CHERRY "IMG/cherry.xpm"
#define CHERRY_C 'C'

void	place_exit(t_vars *vars, t_img *img, t_node *map)
{
	int		x;
	int		y;
	t_img	sprite;

	x = 0;
	y = 0;
	sprite.img = mlx_xpm_file_to_image(vars->mlx, EXIT, \
		&vars->img_width, &vars->img_height);
	if (sprite.img == NULL)
		exit (error_message());
	sprite.addr = mlx_get_data_addr(sprite.img, &sprite.bits_per_pixel, \
		&sprite.line_length, &sprite.endian);
	while (map != NULL)
	{
		if (map->number == EXIT_E)
			draw_sprite(img, &sprite, x, y);
		map = map->next;
		x = x + 50;
		if (x / 50 >= vars->width)
		{
			y = y + 50;
			x = 0;
		}
	}
}

void	place_cherry(t_vars *vars, t_img *img, t_node *map)
{
	int		x;
	int		y;
	t_img	sprite;

	x = 0;
	y = 0;
	sprite.img = mlx_xpm_file_to_image(vars->mlx, CHERRY, \
		&vars->img_width, &vars->img_height);
	if (sprite.img == NULL)
		exit (error_message());
	sprite.addr = mlx_get_data_addr(sprite.img, &sprite.bits_per_pixel, \
		&sprite.line_length, &sprite.endian);
	while (map != NULL)
	{
		if (map->number == CHERRY_C)
			draw_sprite(img, &sprite, x, y);
		map = map->next;
		x = x + 50;
		if (x / 50 >= vars->width)
		{
			y = y + 50;
			x = 0;
		}
	}
}

void	place_player(t_vars *vars, t_img *img, t_node *map)
{
	int		x;
	int		y;
	t_img	sprite;

	x = 0;
	y = 0;
	animation_player(vars, &sprite);
	sprite.addr = mlx_get_data_addr(sprite.img, &sprite.bits_per_pixel, \
		&sprite.line_length, &sprite.endian);
	while (map != NULL)
	{
		if (map->number == PLAYER_P)
			draw_sprite(img, &sprite, x, y);
		map = map->next;
		x = x + 50;
		if (x / 50 >= vars->width)
		{
			y = y + 50;
			x = 0;
		}
	}
}

void	place_wall(t_vars *vars, t_img *img, t_node *map)
{
	int		x;
	int		y;
	t_img	sprite;

	x = 0;
	y = 0;
	sprite.img = mlx_xpm_file_to_image(vars->mlx, WALL, \
		&vars->img_width, &vars->img_height);
	if (sprite.img == NULL)
		exit (error_message());
	sprite.addr = mlx_get_data_addr(sprite.img, &sprite.bits_per_pixel, \
		&sprite.line_length, &sprite.endian);
	while (map != NULL)
	{
		if (map->number == WALL_INT)
			draw_sprite(img, &sprite, x, y);
		map = map->next;
		x = x + 50;
		if (x / 50 >= vars->width)
		{
			y = y + 50;
			x = 0;
		}
	}
}

void	place_background(t_vars *vars, t_img *img, t_node *map)
{
	int		x;
	int		y;
	t_img	sprite;

	x = 0;
	y = 0;
	sprite.img = mlx_xpm_file_to_image(vars->mlx, GRASS, \
		&vars->img_width, &vars->img_height);
	if (sprite.img == NULL)
		exit (error_message());
	sprite.addr = mlx_get_data_addr(sprite.img, &sprite.bits_per_pixel, \
		&sprite.line_length, &sprite.endian);
	while (map != NULL)
	{
		draw_sprite(img, &sprite, x, y);
		map = map->next;
		x = x + 50;
		if (x / 50 >= vars->width)
		{
			y = y + 50;
			x = 0;
		}
	}
}
