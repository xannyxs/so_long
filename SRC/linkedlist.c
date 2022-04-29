/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linkedlist.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 15:53:56 by xander        #+#    #+#                 */
/*   Updated: 2022/04/29 12:34:50 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_lstlen(t_node *head)
{
	int	len;

	len = 0;
	while (head != NULL)
	{
		head = head->next;
		len++;
	}
	return (len);
}

int	free_list(t_node **head)
{
	t_node	*temp;

	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	return (0);
}

int	new_node(t_node **head, int value)
{
	t_node	*new_node;
	t_node	*last_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		free(new_node);
		return (-1);
	}
	new_node->number = value;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		last_node = *head;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
	}
	return (0);
}

int	insert_to_list(t_vars *vars, t_node **map, char *line)
{
	int	i;
	int	c;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] - '0' == 0 || line[i] - '0' == 1)
			c = line[i] - '0';
		else
			c = line[i];
		if (vars->p_check == 0 && c == 'P')
			vars->p_check = 1;
		else if (c == 'P')
			c = 0;
		if (new_node(map, c) < 0)
		{
			free_list(map);
			free(line);
			return (-1);
		}
		i++;
	}
	return (0);
}
