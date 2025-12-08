/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kedemiro <kedemiro@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:26:47 by kedemiro          #+#    #+#             */
/*   Updated: 2025/11/30 19:23:09 by kedemiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_t_data(t_data *data, int ac, char **av)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->argv = NULL;
	data->before_split = av[1];
	data->argc = ac -1;
	data->av = av;
	data->ac = ac;
	data->exit_status = -1;
	data->allocated = 0;
}

void	null_check(t_data *data)
{
	int	i;

	i = 0;
	while (data->av[i])
	{
		if (!data->av[i][0] || (data->av[i][0] == ' ' && !data->av[i][1]))
			pexit(data, -1);
		i++;
	}
}

int	line_len(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	compact_args(t_data *data)
{
	char	*res;
	int		i;
	int		all_size;

	i = 0;
	all_size = 0;
	if (data->ac == 2)
		return (0);
	while (++i < data->ac)
		all_size += line_len(data->av[i]);
	i = 1;
	res = calloc(sizeof(char), all_size + 1 + data->ac -2);
	if (!res)
		return (-1);
	while (i < data->ac)
	{
		ft_strlcat(res, data->av[i], line_len(res) + line_len(data->av[i]) + 1);
		if (data->av[i] && data->av[i][0] != '\0' && i != data->ac -1)
			ft_strlcat(res, " ", line_len(res) + 2);
		i++;
	}
	data->before_split = res;
	data->ac = 2;
	data->allocated = 1;
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
		return (0);
	start_t_data(&data, ac, av);
	null_check(&data);
	if (compact_args(&data) < 0)
		pexit(&data, -1);
	char_to_int(&data);
	sort_int(&data);
	if (is_already_sorted(&data))
	{
		pexit(&data, 1);
		return (0);
	}
	if (data.argc > 1 && data.argc < 9)
		under_nine(&data);
	else
		radix_sort(&data);
	pexit(&data, 1);
}
