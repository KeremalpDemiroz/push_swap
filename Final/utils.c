/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kedemiro <kedemiro@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:14:59 by kedemiro          #+#    #+#             */
/*   Updated: 2025/11/30 18:15:35 by kedemiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_node(t_list **list)
{
	t_list	*temp;

	while (*list)
	{
		temp = (*list)->next;
		free(*list);
		*list = temp;
	}
	*list = NULL;
}

void	all_free(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	pexit(t_data *data, int exit_status)
{
	if (data->argv && data->allocated)
	{
		all_free(data->argv);
		data->argv = NULL;
	}
	if (data->stack_a)
		free_node(&data->stack_a);
	if (data->stack_b)
		free_node(&data->stack_b);
	if (exit_status < 0)
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
