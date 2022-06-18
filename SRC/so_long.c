/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 14:54:29 by xander        #+#    #+#                 */
/*   Updated: 2022/06/18 19:19:02 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error.h"

#include <stdbool.h>

/*
	Key_press will track actions of the user.
	Both WASD & ARROWS work to move the character.
	ESC is to close the game.
*/

//int	mouse_press(t_vars *vars)
//{
//	mlx_destroy_window(vars->mlx, vars->win);
//	exit(0);
//}

//int	key_press(int keycode, t_vars *vars)
//{
//	if (keycode == ESC)
//	{
//		mlx_destroy_window(vars->mlx, vars->win);
//		exit(0);
//	}
//	else if (keycode == ARROW_LEFT || keycode == KEY_A)
//		to_left(vars);
//	else if (keycode == ARROW_RIGHT || keycode == KEY_D)
//		to_right(vars);
//	else if (keycode == ARROW_UP || keycode == KEY_W)
//		to_up(vars);
//	else if (keycode == ARROW_DOWN || keycode == KEY_S)
//		to_down(vars);
//	if (check_collectables(vars->map) == -1)
//		vars->enter_exit = true;
//	return (0);
//}

static void	set_values(t_vars *vars)
{
	vars->collectables = 0;
	vars->enter_exit = false;
	vars->buffer = -1;
	vars->p_check = 0;
}

int32_t	main(int argc, char *argv[])
{
	t_vars	vars;

	set_values(&vars);
	if (argc != 2)
	{
		non_fatal_error(ARGC_ERROR);
		return (ERROR);
	}
	if (is_ber_file_valid(argv[1], &vars))
		return (ERROR);
	vars.mlx = mlx_init(vars.map_data.width * 50, vars.map_data.height * 50, "SO_LONG", false);
	//if (!vars.mlx)
	//	return (error_message());
	//vars.win = mlx_new_window(vars.mlx, vars.width * 50, vars.height * 50, \
	//	"Crab & Cherry");
	//if (vars.win == NULL)
	//	return (error_message());
	//place_all_objects(vars, map);
	//vars.map = map;
	//mlx_key_hook(vars.win, key_press, &vars);
	//mlx_hook(vars.win, 17, 1l << 17, mouse_press, &vars);
	//mlx_loop(vars.mlx);
	return (ERROR);
}
