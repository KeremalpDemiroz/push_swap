/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_moves_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kedemiro <kedemiro@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:54:23 by kedemiro          #+#    #+#             */
/*   Updated: 2025/11/30 17:55:05 by kedemiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_data *data)
{
	t_list	*first;
	t_list	*second;

	if (!data->stack_b || !(data->stack_b->next))
		return ;
	first = data->stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	data->stack_b = second;
	ft_putendl_fd("sb", 1);
}

void	rotate_b(t_data *data)
{
	t_list	*tmp;
	t_list	*first;

	if (!data->stack_b || !data->stack_b->next)
		return ;
	tmp = data->stack_b;
	first = tmp;
	data->stack_b = tmp->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	first->next = NULL;
	ft_putendl_fd("rb", 1);
}

void	reverse_rotate_b(t_data *data)
{
	t_list	*tmp;
	t_list	*first;
	t_list	*last;

	if (!data->stack_b || !data->stack_b->next)
		return ;
	tmp = data->stack_b;
	first = tmp;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = first;
	data->stack_b = last;
	ft_putendl_fd("rrb", 1);
}

void	push_b(t_data *data)
{
	t_list	*tmp;

	if (!data->stack_a)
		return ;
	tmp = data->stack_a;
	data->stack_a = tmp->next;
	tmp->next = data->stack_b;
	data->stack_b = tmp;
	ft_putendl_fd("pb", 1);
}
