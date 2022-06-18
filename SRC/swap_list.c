///* ************************************************************************** */
///*                                                                            */
///*                                                        ::::::::            */
///*   swap_list.c                                        :+:    :+:            */
///*                                                     +:+                    */
///*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
///*                                                   +#+                      */
///*   Created: 2022/01/25 18:23:08 by xvoorvaa      #+#    #+#                 */
///*   Updated: 2022/04/29 12:34:40 by xander        ########   odam.nl         */
///*                                                                            */
///* ************************************************************************** */

//#include "so_long.h"

//int	swap_list_left(t_vars *vars, t_node *new_list)
//{
//	if (new_list->next->number == 'C')
//		vars->collectables++;
//	if (new_list->number == 'E' && vars->enter_exit == true)
//		exit (0);
//	if (vars->buffer != -1 && vars->buffer != 'C')
//	{
//		new_list->next->number = vars->buffer;
//		vars->buffer = new_list->number;
//		new_list->number = 'P';
//	}
//	else
//	{
//		vars->buffer = new_list->number;
//		new_list->number = 'P';
//		new_list->next->number = 0;
//	}
//	place_all_objects(*vars, vars->map);
//	return (0);
//}

//int	swap_list_right(t_vars *vars, t_node *new_list)
//{
//	if (new_list->next->number == 'C')
//		vars->collectables++;
//	if (new_list->next->number == 'E' && vars->enter_exit == true)
//		exit (0);
//	if (vars->buffer != -1 && vars->buffer != 'C')
//	{
//		new_list->number = vars->buffer;
//		vars->buffer = new_list->next->number;
//		new_list->next->number = 'P';
//	}
//	else
//	{
//		vars->buffer = new_list->next->number;
//		new_list->next->number = 'P';
//		new_list->number = 0;
//	}
//	place_all_objects(*vars, vars->map);
//	return (0);
//}

//int	swap_list_down(t_vars *vars, t_node *new_list, t_node *down_node)
//{
//	if (down_node->number == 'C')
//		vars->collectables++;
//	if (down_node->number == 'E' && vars->enter_exit == true)
//		exit (0);
//	if (vars->buffer != -1 && vars->buffer != 'C')
//	{
//		new_list->number = vars->buffer;
//		vars->buffer = down_node->number;
//		down_node->number = 'P';
//	}
//	else
//	{
//		vars->buffer = down_node->number;
//		down_node->number = 'P';
//		new_list->number = 0;
//	}
//	place_all_objects(*vars, vars->map);
//	return (0);
//}

//int	swap_list_up(t_vars *vars, t_node *new_list, t_node *upper_node)
//{
//	if (upper_node->number == 'C')
//		vars->collectables++;
//	if (upper_node->number == 'E' && vars->enter_exit == true)
//		exit (0);
//	if (vars->buffer != -1 && vars->buffer != 'C')
//	{
//		new_list->number = vars->buffer;
//		vars->buffer = upper_node->number;
//		upper_node->number = 'P';
//	}
//	else
//	{
//		vars->buffer = upper_node->number;
//		upper_node->number = 'P';
//		new_list->number = 0;
//	}
//	place_all_objects(*vars, vars->map);
//	return (0);
//}
