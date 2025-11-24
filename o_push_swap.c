#include "push_swap.h"
#include <stdio.h>

void	free_node(t_list **list)
{
	t_list *temp;

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
	int i;

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

void	pexit(t_data *data)//data_list parametre alınıp data_list içinde ki alanlar freelenebilir çıkış öncesi
{
	if (data->argv && data->allocated)
	{
		all_free(data->argv);
		data->argv = NULL;
	}
	if (data->stacka)
		free_node(&data->stacka);
	if (data->stackb)
		free_node(&data->stackb);
	if (data->exit_status < 0)
	{
		ft_putendl_fd("Error!", 2);
		exit(EXIT_FAILURE);
	}
}

int	ft_atoi_ps(t_data *data, int i)//atoi ve INT_MIN || INT_MAX kontrolü
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
		pexit(data);
	return ((int)result * sign);
}

void	start_t_data(t_data *data, int ac, char **av)
{
	data->stacka = NULL;
	data->stackb = NULL;
	data->argv = NULL;
	data->argc = ac -1;
	data->av = av;
	data->ac = ac;
	data->exit_status = -1;
	data->allocated = 0; 
}
int	get_argc(t_data *data) // ft_strlen for double pointer
{
	int	i;

	i = 0;
	if (!data->argv)
		pexit(data);
	while (data->argv[i])
		i++;
	return (i);
}

void	args_is_int(t_data *data) //isdigit ve ft_strlen() > 10 kontrolü
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
			pexit(data);
		while (data->argv[i][j])
		{
			if (!ft_isdigit(data->argv[i][j]))
				pexit(data);
			j++;
		}
		i++;
	}
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

t_list	*new_node(int arg, int index, t_data *data)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	if (!node)
	{
		pexit(data);
	}
	node->arg = arg;
	node->index = index;
	node->next = NULL;
	return (node);
}

t_list	*doppelganger(t_data *data)
{
	t_list	*clone;
	t_list	*tmp;

	clone = NULL;
	tmp = data->stacka;
	while (tmp)
	{
		add_back(&clone, new_node(tmp->arg, tmp->index, data));
		tmp = tmp->next;
	}
	return (clone);
}
void	arg_to_index(t_data *data, t_list *copy)
{
	t_list	*stack_tmp;
	t_list	*copy_tmp;

	stack_tmp = data->stacka;
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
}
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
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
			pexit(data);
		}
		tmp_arg = tmp_copy->arg;
		tmp_copy = tmp_copy->next;
	}
}

void	sort_int(t_data *data)
{
	t_list	*copy;
	t_list	*tmp_out;
	t_list	*tmp_in;
	int		i;

	i = 0;
	copy = doppelganger(data);
	tmp_out  = copy;
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

void	char_to_int(t_data *data)
{
	int	i;
	int	tmp;

	i = 0;
	if (data->ac == 2)
	{
		data->argv = ft_split(data->av[1], ' ');
		if (!data->argv)
			pexit(data);
		data->argc = get_argc(data);
		data->allocated = 1;
	}
	else
		data->argv = &data->av[1];
	args_is_int(data);
	while (i < data->argc)
	{
		tmp = ft_atoi_ps(data, i);
		add_back(&data->stacka, new_node(tmp, 0, data));
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
		return (0);
	start_t_data(&data, ac, av);
	char_to_int(&data);
	sort_int(&data);
	t_list *tmp = data.stacka;
	while (tmp)
	{
		printf("arg: %d || index: %d", tmp->arg, tmp->index);
		if (tmp->next == NULL)
			printf("\n");
		else
			printf(" ");
		tmp = tmp->next;
	}
	data.exit_status = 1;
	pexit(&data);
}