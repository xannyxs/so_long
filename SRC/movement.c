///* ************************************************************************** */
///*                                                                            */
///*                                                        ::::::::            */
///*   movement.c                                         :+:    :+:            */
///*                                                     +:+                    */
///*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
///*                                                   +#+                      */
///*   Created: 2022/01/17 23:21:59 by xvoorvaa      #+#    #+#                 */
///*   Updated: 2022/04/29 12:34:50 by xander        ########   odam.nl         */
///*                                                                            */
///* ************************************************************************** */

//#include "so_long.h"

//void	print_movement(t_vars *vars)
//{
//	vars->moves++;
//	write(STDOUT_FILENO, "MOVES: ", 7);
//	ft_putnbr_fd(vars->moves, STDOUT_FILENO);
//	write(STDOUT_FILENO, "\n", 1);
//}

//int	to_left(t_vars *vars)
//{
//	t_node	*new_list;

//	new_list = vars->map;
//	vars->ping = 1;
//	while (new_list->next->number != 'P')
//		new_list = new_list->next;
//	if (new_list->number != 1)
//	{
//		print_movement(vars);
//		swap_list_left(vars, new_list);
//	}
//	return (0);
//}

//int	to_right(t_vars *vars)
//{
//	t_node	*new_list;

//	new_list = vars->map;
//	vars->ping = 0;
//	while (new_list->number != 'P')
//		new_list = new_list->next;
//	if (new_list->next->number != 1)
//	{
//		print_movement(vars);
//		swap_list_right(vars, new_list);
//	}
//	return (0);
//}

//int	to_up(t_vars *vars)
//{
//	int		i;
//	t_node	*new_list;
//	t_node	*upper_node;

//	i = 0;
//	new_list = vars->map;
//	upper_node = vars->map;
//	while (new_list->number != 'P')
//	{
//		new_list = new_list->next;
//		i++;
//	}
//	while (i - vars->width > 0)
//	{
//		upper_node = upper_node->next;
//		i--;
//	}
//	if (upper_node->number != 1)
//	{
//		print_movement(vars);
//		swap_list_up(vars, new_list, upper_node);
//	}
//	return (0);
//}

//int	to_down(t_vars *vars)
//{
//	int		i;
//	t_node	*new_list;
//	t_node	*down_node;

//	i = 0;
//	new_list = vars->map;
//	down_node = vars->map;
//	while (new_list->number != 'P')
//	{
//		new_list = new_list->next;
//		i++;
//	}
//	while (i + vars->width > 0)
//	{
//		down_node = down_node->next;
//		i--;
//	}
//	if (down_node->number != 1)
//	{
//		print_movement(vars);
//		swap_list_down(vars, new_list, down_node);
//	}
//	return (0);
//}
