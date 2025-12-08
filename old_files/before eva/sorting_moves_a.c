/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_moves_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kedemiro <kedemiro@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:53:23 by kedemiro          #+#    #+#             */
/*   Updated: 2025/11/30 18:21:46 by kedemiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_data *data)
{
	t_list	*first;
	t_list	*second;

	if (!data->stack_a || !(data->stack_a->next))
		return ;
	first = data->stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	data->stack_a = second;
	ft_putendl_fd("sa", 1);
}

void	rotate_a(t_data *data)
{
	t_list	*tmp;
	t_list	*first;

	if (!data->stack_a || !data->stack_a->next)
		return ;
	tmp = data->stack_a;
	first = tmp;
	data->stack_a = tmp->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	first->next = NULL;
	ft_putendl_fd("ra", 1);
}

void	reverse_rotate_a(t_data *data)
{
	t_list	*tmp;
	t_list	*first;
	t_list	*last;

	if (!data->stack_a || !data->stack_a->next)
		return ;
	tmp = data->stack_a;
	first = tmp;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = first;
	data->stack_a = last;
	ft_putendl_fd("rra", 1);
}

void	push_a(t_data *data)
{
	t_list	*tmp;

	if (!data->stack_b)
		return ;
	tmp = data->stack_b;
	data->stack_b = tmp->next;
	tmp->next = data->stack_a;
	data->stack_a = tmp;
	ft_putendl_fd("pa", 1);
}

