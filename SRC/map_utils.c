/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 12:48:58 by xander        #+#    #+#                 */
/*   Updated: 2022/06/18 19:17:04 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error.h"

#define PLAYER "IMG/mouse.xpm"
#define PLAYER_REVERSE "IMG/mouse_reverse.xpm"

//void	animation_player(t_vars *vars, t_img *sprite)
//{
//	sprite->img = mlx_xpm_file_to_image(vars->mlx, PLAYER, \
//		&vars->img_width, &vars->img_height);
//	if (vars->ping == 1)
//		sprite->img = mlx_xpm_file_to_image(vars->mlx, PLAYER_REVERSE, \
//			&vars->img_width, &vars->img_height);
//	if (sprite->img == NULL)
//		exit (error_message());
//}
