/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   place_obj.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/16 17:03:16 by xander        #+#    #+#                 */
/*   Updated: 2022/06/27 11:49:22 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_objects(void *param)
{
	t_vars	*vars;

	vars = param;
	place_background(vars);
	place_wall(vars);
	place_exit(vars);
	place_cherry(vars);
	place_player(vars);
}
