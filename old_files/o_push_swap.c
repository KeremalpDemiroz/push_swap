#include "push_swap.h"
#include <stdio.h>

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

//isdigit ve ft_strlen() > 10 kontrolü
void	args_is_int(t_data *data)
{
	int		j;
	int		i;
	char	**argv;

	i = 0;
	argv = data->argv;
	while (argv[i])
	{
		j = 0;
		if ((argv[i][j] == '-' || argv[i][j] == '+') && argv[i][j+1] != '\0')
			j++;
		while (argv[i][j] == '0')
			j++;
		if (ft_strlen(&argv[i][j]) > 10)
			pexit(data, -1);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				pexit(data, -1);
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
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		pexit(data, -1);
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
	tmp = data->stack_a;
	while (tmp)
	{
		add_back(&clone, new_node(tmp->arg, tmp->index, data));
		tmp = tmp->next;
	}
	return (clone);
}

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
			pexit(data, -1);
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

void	checker(t_data *data)
{
	t_list	*tmp_copy;
	int		tmp_arg;

	if (data->argc == 1)
		return ;
	tmp_arg = data->stack_a->arg;
	tmp_copy = data->stack_a->next;
	while (tmp_copy)
	{
		if (tmp_arg > tmp_copy->arg)
			pexit(data, -1);
		tmp_arg = tmp_copy->arg;
		tmp_copy = tmp_copy->next;
	}
	printf("   OK \n");
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
	int	position;
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

void	null_check(t_data *data)
{
	int	i;

	i = 0;
	while (data->av[i])
	{
		if (!data->av[i][0])
			pexit(data, -1);
		i++;
	}
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
	if (data.argc < 9 && data.argc > 1)
	{
		under_nine(&data);
	}
	else
	{

		radix_sort(&data);
	}
	pexit(&data, 1);
}

/*

to do :
		3 ve 5 elemanlıda ki max 2 ve 12 hamle için optimize et
		// 5 ve 6 için yazıldı 3 optimize edilmeli
		Makefile yaz
		norm düzelt
		tester ile test et
*/

/*


				stack_a										stack_b
	8843	9581	7556	4562	17159
	2		3		1		0		4


	4	2	3	1	0
	0	4	2	3	1

	4	2	3	1												0
	1	4	2	3												0
	4	2	3						1	0
	2	3	4					1	0
	3	4					


	12 hamle = 0 2 1 4 3 
	
	16 hamle = 1 2 3 0 4
	17 hamle = 1 3 2 0 4
	12 hamle = 1 0 3 2 4

	14 hamle = 2 3 1 0 4
	14 hamle = 3 2 0 4 1
	13 hamle = 3 1 0 4 2
	15 hamle = 4 0 2 3 1
	12 hamle = 4 0 2 1 3



	0 3 2 4 1

	3 2 4 1       0
	2 4 1 3       0


	4 0 3 2 1
	
	4 0 3 1 2


	0 3 1 2 4

	3 1 2 4 = 0
	1 2 4 3 = 0
	2 4 3 = 1 0
	4 3 = 2 1

*/
