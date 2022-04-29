/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/16 15:28:38 by xander        #+#    #+#                 */
/*   Updated: 2022/04/29 13:05:31 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_player(t_node *map)
{
	while (map != NULL)
	{
		if (map->number == 'P')
			return (0);
		map = map->next;
	}
	return (-1);
}

int	check_collectables(t_node *map)
{
	while (map != NULL)
	{
		if (map->number == 'C')
			return (0);
		map = map->next;
	}
	return (-1);
}

int	check_exit(t_node *map)
{
	while (map != NULL)
	{
		if (map->number == 'E')
			return (0);
		map = map->next;
	}
	return (-1);
}

int	check_unknown(t_node *map)
{
	while (map != NULL)
	{
		if (!(map->number == 'E' || map->number == 'P' || \
			map->number == 'C' || map->number == 1 || map->number == 0))
			return (-1);
		map = map->next;
	}
	return (0);
}

int	check_wall(t_vars *vars, t_node *map)
{
	int	i;
	int	j;
	int	len_list;

	i = 0;
	j = 0;
	len_list = ft_lstlen(map);
	vars->width = len_list / vars->height;
	while (i < vars->height)
	{
		while (j < vars->width)
		{
			if (map->number != 1 && i == 0)
				return (-1);
			else if (map->number != 1 && i == vars->height - 1)
				return (-1);
			else if (map->number != 1 && (j == 0 || j == vars->width - 1))
				return (-1);
			map = map->next;
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
