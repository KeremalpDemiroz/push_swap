/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_nine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kedemiro <kedemiro@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:52:30 by kedemiro          #+#    #+#             */
/*   Updated: 2025/11/30 18:21:23 by kedemiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_data *data, int target_index)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = data->stack_a;
	while (tmp)
	{
		if (tmp->index == target_index)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

void	bring_to_top(t_data *data, int target_index)
{
	int	position;
	int	node_count;

	position = get_position(data, target_index);
	node_count = count_node(data);
	if (position <= node_count / 2)
	{
		while (get_position(data, target_index) != 0)
		{
			if (data->stack_a->index == data->stack_a->next->index +1)
				swap_a(data);
			else
				rotate_a(data);
		}
	}
	else
	{
		while (get_position(data, target_index) != 0)
			reverse_rotate_a(data);
	}
}

void	under_nine(t_data *data)
{
	int	min_index;
	int	max_index;

	max_index = data->argc -1;
	min_index = 0;
	if (max_index >= 3)
	{
		while (min_index <= data->argc / 2)
		{
			bring_to_top(data, min_index);
			if (is_already_sorted(data))
				break ;
			else
				push_b(data);
			min_index++;
		}
	}
	while (is_already_sorted(data) == 0 && min_index <= max_index)
	{
		bring_to_top(data, max_index);
		max_index--;
	}
	while (data->stack_b)
		push_a(data);
}
