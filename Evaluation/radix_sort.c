/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kedemiro <kedemiro@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:56:37 by kedemiro          #+#    #+#             */
/*   Updated: 2025/11/30 18:16:20 by kedemiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_data *data)
{
	int		i;

	i = 0;
	while (i <= data->max_bit)
	{
		data->node_count = count_node(data);
		while (data->node_count > 0)
		{
			if (!((data->stack_a->index >> i) & 1))
				push_b(data);
			else
				rotate_a(data);
			(data->node_count)--;
		}
		while (data->stack_b)
			push_a(data);
		i++;
	}
}
