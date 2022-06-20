/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 23:21:59 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/20 22:58:45 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static void	print_movement(t_vars *vars)
{
	vars->moves++;
	write(STDOUT_FILENO, "MOVES: ", 7);
	ft_putnbr_fd(vars->moves, STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
}

static void	reset_image(mlx_image_t *img)
{
	ft_memset(img->pixels, 0, img->width * img->height * sizeof(int));
}

void	to_left(t_vars *vars)
{
	if (vars->map_data.world_map[vars->player_y][vars->player_x - 1] != '1')
	{
		vars->map_data.world_map[vars->player_y][vars->player_x] = vars->last_tile;
		if (vars->map_data.world_map[vars->player_y][vars->player_x - 1] == 'C')
			vars->last_tile = '0';
		else if (vars->map_data.world_map[vars->player_y][vars->player_x - 1] == 'E' && vars->enter_exit == true)
			mlx_close_window(vars->mlx);
		else
			vars->last_tile = vars->map_data.world_map[vars->player_y][vars->player_x - 1];
		vars->map_data.world_map[vars->player_y][vars->player_x - 1] = 'P';
		vars->player_x--;
		reset_image(vars->screen);
		place_objects(vars);
		print_movement(vars);
	}
}

void	to_right(t_vars *vars)
{
	if (vars->map_data.world_map[vars->player_y][vars->player_x + 1] != '1')
	{
		vars->map_data.world_map[vars->player_y][vars->player_x] = vars->last_tile;
		if (vars->map_data.world_map[vars->player_y][vars->player_x + 1] == 'C')
			vars->last_tile = '0';
		else if (vars->map_data.world_map[vars->player_y][vars->player_x + 1] == 'E' && vars->enter_exit == true)
			mlx_close_window(vars->mlx);
		else
			vars->last_tile = vars->map_data.world_map[vars->player_y][vars->player_x + 1];
		vars->map_data.world_map[vars->player_y][vars->player_x + 1] = 'P';
		vars->player_x++;
		reset_image(vars->screen);
		place_objects(vars);
		print_movement(vars);
	}
}

void	to_up(t_vars *vars)
{
	if (vars->map_data.world_map[vars->player_y - 1][vars->player_x] != '1')
	{
		vars->map_data.world_map[vars->player_y][vars->player_x] = vars->last_tile;
		if (vars->map_data.world_map[vars->player_y - 1][vars->player_x] == 'C')
			vars->last_tile = '0';
		else if (vars->map_data.world_map[vars->player_y - 1][vars->player_x] == 'E' && vars->enter_exit == true)
			mlx_close_window(vars->mlx);
		else
			vars->last_tile = vars->map_data.world_map[vars->player_y - 1][vars->player_x];
		vars->map_data.world_map[vars->player_y - 1][vars->player_x] = 'P';
		vars->player_y--;
		reset_image(vars->screen);
		place_objects(vars);
		print_movement(vars);
	}
}

void	to_down(t_vars *vars)
{
	if (vars->map_data.world_map[vars->player_y + 1][vars->player_x] != '1')
	{
		vars->map_data.world_map[vars->player_y][vars->player_x] = vars->last_tile;
		if (vars->map_data.world_map[vars->player_y + 1][vars->player_x] == 'C')
			vars->last_tile = '0';
		else if (vars->map_data.world_map[vars->player_y + 1][vars->player_x] == 'E' && vars->enter_exit == true)
			mlx_close_window(vars->mlx);
		else
			vars->last_tile = vars->map_data.world_map[vars->player_y + 1][vars->player_x];
		vars->map_data.world_map[vars->player_y + 1][vars->player_x] = 'P';
		vars->player_y++;
		reset_image(vars->screen);
		place_objects(vars);
		print_movement(vars);
	}
}
