/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kedemiro <kedemiro@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:35:53 by kedemiro          #+#    #+#             */
/*   Updated: 2025/11/30 17:43:35 by kedemiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_argc(t_data *data)
{
	int	i;

	i = 0;
	if (!data->argv)
		pexit(data, -1);
	while (data->argv[i])
		i++;
	return (i);
}

void	args_is_int(t_data *data)
{
	int	j;
	int	i;

	i = 0;
	while (data->argv[i])
	{
		j = 0;
		if (data->argv[i][j] == '-' || data->argv[i][j] == '+')
			j++;
		while (data->argv[i][j] == '0')
			j++;
		if (ft_strlen(&data->argv[i][j]) > 10)
			pexit(data, -1);
		while (data->argv[i][j])
		{
			if (!ft_isdigit(data->argv[i][j]))
				pexit(data, -1);
			j++;
		}
		i++;
	}
}

int	ft_atoi_ps(t_data *data, int i)
{
	long int	sign;
	long int	result;
	char		*str;

	result = 0;
	sign = 1;
	str = data->argv[i];
	while (((*str) >= 9 && (*str) <= 13) || (*str) == 32)
		str++;
	if ((*str) == '-' || (*str) == '+')
	{
		if ((*str) == '-')
			sign *= -1;
		str++;
	}
	while ((*str) >= '0' && (*str) <= '9')
	{
		result = (result * 10) + ((*str) - 48);
		str++;
	}
	if (result * sign > INT_MAX || result * sign < INT_MIN)
		pexit(data, -1);
	return ((int)result * sign);
}

void	char_to_int(t_data *data)
{
	int	i;
	int	tmp;

	i = 0;
	if (!data->before_split || data->before_split[0] == '\0')
		pexit(data, -1);
	data->argv = ft_split(data->before_split, ' ');
	if (!data->argv)
		pexit(data, -1);
	data->argc = get_argc(data);
	if (data->allocated)
		free(data->before_split);
	data->allocated = 1;
	args_is_int(data);
	while (i < data->argc)
	{
		tmp = ft_atoi_ps(data, i);
		add_back(&data->stack_a, new_node(tmp, 0, data));
		i++;
	}
}
