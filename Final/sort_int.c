/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kedemiro <kedemiro@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:45:20 by kedemiro          #+#    #+#             */
/*   Updated: 2025/11/30 18:15:47 by kedemiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_msb(t_data *data)
{
	int	msb;
	int	max_index;

	max_index = (data->argc) - 1;
	msb = -1;
	while (max_index > 0)
	{
		max_index = max_index >> 1;
		msb++;
	}
	return (msb);
}

t_list	*doppelganger(t_data *data)
{
	t_list	*clone;
	t_list	*tmp;

	clone = NULL;
	tmp = data->stack_a;
	while (tmp)
	{
		add_back(&clone, new_node(tmp->arg, tmp->index, data));
		tmp = tmp->next;
	}
	return (clone);
}

void	arg_is_uniq(t_data *data, t_list **copy)
{
	t_list	*tmp_copy;
	int		tmp_arg;

	tmp_arg = (*copy)->arg;
	tmp_copy = (*copy)->next;
	while (tmp_copy)
	{
		if (tmp_arg == tmp_copy->arg)
		{
			free_node(copy);
			pexit(data, -1);
		}
		tmp_arg = tmp_copy->arg;
		tmp_copy = tmp_copy->next;
	}
}

void	arg_to_index(t_data *data, t_list *copy)
{
	t_list	*stack_tmp;
	t_list	*copy_tmp;

	stack_tmp = data->stack_a;
	while (stack_tmp)
	{
		copy_tmp = copy;
		while (copy_tmp)
		{
			if (stack_tmp->arg == copy_tmp->arg)
				stack_tmp->index = copy_tmp->index;
			copy_tmp = copy_tmp->next;
		}
		stack_tmp = stack_tmp->next;
	}
	data->max_bit = find_msb(data);
	if (data->max_bit == -1)
		pexit(data, 1);
}

void	sort_int(t_data *data)
{
	t_list	*copy;
	t_list	*tmp_out;
	t_list	*tmp_in;
	int		i;

	i = 0;
	copy = doppelganger(data);
	tmp_out = copy;
	while (tmp_out)
	{
		tmp_in = tmp_out->next;
		while (tmp_in)
		{
			if (tmp_out->arg > tmp_in->arg)
				ft_swap(&tmp_out->arg, &tmp_in->arg);
			tmp_in = tmp_in->next;
		}
		tmp_out->index = i;
		tmp_out = tmp_out->next;
		i++;
	}
	arg_is_uniq(data, &copy);
	arg_to_index(data, copy);
	free_node(&copy);
}
