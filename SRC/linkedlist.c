/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linkedlist.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 15:53:56 by xander        #+#    #+#                 */
/*   Updated: 2022/06/27 11:12:04 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdlib.h> /* free */

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

void	ft_free_list(t_node **head)
{
	t_node	*temp;

	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

void	new_node(t_node **head, char *data)
{
	t_node	*new_node;
	t_node	*last_node;

	new_node = ft_malloc(sizeof(t_node));
	new_node->data = data;
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
}
