/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 23:21:59 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/27 11:18:20 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	to_left(t_vars *vars, char *world_map[])
{
	if (world_map[vars->player_y][vars->player_x - 1] != '1')
	{
		world_map[vars->player_y][vars->player_x] = vars->last_tile;
		if (world_map[vars->player_y][vars->player_x - 1] == 'C')
			vars->last_tile = '0';
		else if (world_map[vars->player_y][vars->player_x - 1] == 'E' && \
			vars->enter_exit == true)
			mlx_close_window(vars->mlx);
		else
			vars->last_tile = world_map[vars->player_y][vars->player_x - 1];
		world_map[vars->player_y][vars->player_x - 1] = 'P';
		vars->player_x--;
		reset_image(vars->screen);
		place_objects(vars);
		print_movement(vars);
	}
}

void	to_right(t_vars *vars, char *world_map[])
{
	if (world_map[vars->player_y][vars->player_x + 1] != '1')
	{
		world_map[vars->player_y][vars->player_x] = vars->last_tile;
		if (world_map[vars->player_y][vars->player_x + 1] == 'C')
			vars->last_tile = '0';
		else if (world_map[vars->player_y][vars->player_x + 1] == 'E' && \
			vars->enter_exit == true)
			mlx_close_window(vars->mlx);
		else
			vars->last_tile = world_map[vars->player_y][vars->player_x + 1];
		world_map[vars->player_y][vars->player_x + 1] = 'P';
		vars->player_x++;
		reset_image(vars->screen);
		place_objects(vars);
		print_movement(vars);
	}
}

void	to_up(t_vars *vars, char *world_map[])
{
	if (world_map[vars->player_y - 1][vars->player_x] != '1')
	{
		world_map[vars->player_y][vars->player_x] = vars->last_tile;
		if (world_map[vars->player_y - 1][vars->player_x] == 'C')
			vars->last_tile = '0';
		else if (world_map[vars->player_y - 1][vars->player_x] == 'E' && \
			vars->enter_exit == true)
			mlx_close_window(vars->mlx);
		else
			vars->last_tile = world_map[vars->player_y - 1][vars->player_x];
		world_map[vars->player_y - 1][vars->player_x] = 'P';
		vars->player_y--;
		reset_image(vars->screen);
		place_objects(vars);
		print_movement(vars);
	}
}

void	to_down(t_vars *vars, char *world_map[])
{
	if (world_map[vars->player_y + 1][vars->player_x] != '1')
	{
		world_map[vars->player_y][vars->player_x] = vars->last_tile;
		if (world_map[vars->player_y + 1][vars->player_x] == 'C')
			vars->last_tile = '0';
		else if (world_map[vars->player_y + 1][vars->player_x] == 'E' && \
			vars->enter_exit == true)
			mlx_close_window(vars->mlx);
		else
			vars->last_tile = world_map[vars->player_y + 1][vars->player_x];
		world_map[vars->player_y + 1][vars->player_x] = 'P';
		vars->player_y++;
		reset_image(vars->screen);
		place_objects(vars);
		print_movement(vars);
	}
}
