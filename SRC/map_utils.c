/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 12:48:58 by xander        #+#    #+#                 */
/*   Updated: 2022/04/29 13:03:40 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define PLAYER "IMG/mouse.xpm"
#define PLAYER_REVERSE "IMG/mouse_reverse.xpm"

void	animation_player(t_vars *vars, t_img *sprite)
{
	sprite->img = mlx_xpm_file_to_image(vars->mlx, PLAYER, \
		&vars->img_width, &vars->img_height);
	if (vars->ping == 1)
		sprite->img = mlx_xpm_file_to_image(vars->mlx, PLAYER_REVERSE, \
			&vars->img_width, &vars->img_height);
	if (sprite->img == NULL)
		exit (error_message());
}

int	check_map(t_vars *vars, t_node *map)
{
	if (check_wall(vars, map) != 0)
	{
		write (2, "Error\n", 6);
		perror("Missing walls");
		exit (-1);
	}
	if (check_player(map) != 0)
	{
		write (2, "Error\n", 6);
		perror("Missing player");
		exit (-1);
	}
	if (check_collectables(map) != 0 || check_exit(map) != 0)
	{
		write (2, "Error\n", 6);
		perror("Missing item(s)");
		exit (-1);
	}
	if (check_unknown(map) != 0)
	{
		write (2, "Error\n", 6);
		perror("Unknown character");
		exit (-1);
	}
	return (0);
}

int	get_line(int fd, char *line, t_node **map, t_vars *vars)
{
	while (get_next_line(fd, &line) > 0)
	{
		if (insert_to_list(vars, map, line) != 0)
		{
			free(line);
			return (-1);
		}
		free(line);
		vars->height++;
	}
	if (ft_strcmp(line, "\n") != 0)
	{
		if (insert_to_list(vars, map, line) != 0)
		{
			free(line);
			return (-1);
		}
		vars->height++;
	}
	free(line);
	return (0);
}
