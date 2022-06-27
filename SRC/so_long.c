/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 14:54:29 by xander        #+#    #+#                 */
/*   Updated: 2022/06/27 11:49:54 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "error.h"

#include <stdbool.h>

#define GRASS "IMG/XPM42/grass.xpm42"
#define WALL "IMG/XPM42/wall.xpm42"
#define CHERRY "IMG/XPM42/cherry.xpm42"
#define EXIT "IMG/XPM42/exit.xpm42"
#define PLAYER "IMG/XPM42/player.xpm42"

/*
	key_hook will track actions of the user.
	Only WASD works to move the player.
	ESC is to close the game.
*/
void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_vars	*vars;

	vars = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(vars->mlx);
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS || \
		keydata.action == MLX_REPEAT))
		to_left(vars, vars->map_data.world_map);
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS || \
		keydata.action == MLX_REPEAT))
		to_right(vars, vars->map_data.world_map);
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS || \
		keydata.action == MLX_REPEAT))
		to_up(vars, vars->map_data.world_map);
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS || \
		keydata.action == MLX_REPEAT))
		to_down(vars, vars->map_data.world_map);
	if (does_collect_exist(vars->map_data.world_map) == false)
		vars->enter_exit = true;
}

static void	open_xpm_files(t_textures *textures)
{
	textures->grass = mlx_load_xpm42(GRASS);
	textures->player = mlx_load_xpm42(PLAYER);
	textures->wall = mlx_load_xpm42(WALL);
	textures->cherry = mlx_load_xpm42(CHERRY);
	textures->exit = mlx_load_xpm42(EXIT);
}

static void	set_values(t_vars *vars)
{
	vars->enter_exit = false;
	vars->moves = 0;
	vars->last_tile = 0;
	open_xpm_files(&vars->texture);
	find_player(vars, vars->map_data.world_map);
}

static void	init_sys(t_vars *vars)
{
	set_values(vars);
	vars->screen = mlx_new_image(vars->mlx, vars->map_data.width * 50, \
		vars->map_data.height * 50);
	if (!vars->screen)
		fatal_perror("mlx");
	mlx_image_to_window(vars->mlx, vars->screen, 0, 0);
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
	vars.mlx = mlx_init(vars.map_data.width * 50, \
		vars.map_data.height * 50, "SO_LONG", true);
	if (!vars.mlx)
		fatal_perror("mlx");
	init_sys(&vars);
	place_objects(&vars);
	mlx_key_hook(vars.mlx, &key_hook, &vars);
	mlx_loop(vars.mlx);
	mlx_terminate(vars.mlx);
	ft_free_array(vars.map_data.world_map);
	return (ERROR);
}
