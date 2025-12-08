/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kedemiro <kedemiro@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:47:37 by kedemiro          #+#    #+#             */
/*   Updated: 2025/11/30 18:15:59 by kedemiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_node(int arg, int index, t_data *data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		pexit(data, -1);
	node->arg = arg;
	node->index = index;
	node->next = NULL;
	return (node);
}

void	add_back(t_list **list, t_list *new)
{
	t_list	*temp;

	if (!*list)
	{
		*list = new;
		return ;
	}
	temp = *list;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

int	count_node(t_data *data)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = data->stack_a;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	is_already_sorted(t_data *data)
{
	t_list	*tmp;
	int		sorted;
	int		node_count;

	sorted = 1;
	node_count = count_node(data);
	if (node_count == 1)
		return (1);
	tmp = data->stack_a;
	while (tmp)
	{
		if (tmp->next && tmp->index == tmp->next->index -1)
			sorted++;
		tmp = tmp->next;
	}
	if (sorted == node_count)
		return (1);
	else
		return (0);
}
