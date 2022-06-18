/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 14:54:29 by xander        #+#    #+#                 */
/*   Updated: 2022/06/18 23:55:12 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "error.h"

#include <stdbool.h>

#define SAND "IMG/XPM42/sand.xpm42"

/*
	Key_press will track actions of the user.
	Both WASD & ARROWS work to move the character.
	ESC is to close the game.
*/
void	key_press(void *param)
{
	t_vars *vars;

	vars = param;
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_LEFT) || mlx_is_key_down(vars->mlx, MLX_KEY_A))
		to_left(vars);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_RIGHT) || mlx_is_key_down(vars->mlx, MLX_KEY_D))
		to_right(vars);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_UP) || mlx_is_key_down(vars->mlx, MLX_KEY_W))
		to_up(vars);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_DOWN) || mlx_is_key_down(vars->mlx, MLX_KEY_S))
		to_down(vars);
	//if (check_collectables(vars->map) == -1)
	//	vars->enter_exit = true;
}

static void	set_values(t_vars *vars)
{
	vars->collectables = 0;
	vars->enter_exit = false;
	vars->p_check = 0;
	vars->moves = 0;
	find_player(vars, vars->map_data.world_map);
}

static void	init_sys(t_vars *vars)
{
	set_values(vars);
	vars->screen = mlx_new_image(vars->mlx, 1920, 1080);
	if (!vars->screen)
		fatal_perror("mlx");
}

int32_t	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
	{
		non_fatal_error(ARGC_ERROR);
		return (ERROR);
	}
	if (is_ber_file_valid(argv[1], &vars) == false)
		return (ERROR);
	vars.mlx = mlx_init(vars.map_data.width * 50, vars.map_data.height * 50, "SO_LONG", false);
	if (!vars.mlx)
		fatal_perror("mlx");
	init_sys(&vars);
	place_objects(&vars);
	mlx_loop_hook(vars.mlx, &key_press, &vars);
	mlx_loop(vars.mlx);
	mlx_terminate(vars.mlx);
	ft_free_array(vars.map_data.world_map);
	return (ERROR);
}
