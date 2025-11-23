#include "push_swap.h"
#include <stdio.h>

// void	pexit(/*add pointers needs to be free*/)//data_list parametre alınıp data_list içinde ki alanlar freelenebilir çıkış öncesi
// {
// 	ft_putendl_fd("Error!", 2);
// 	exit(EXIT_FAILURE);
// }
// int	ft_atoi(const char *nptr)//atoi ve INT_MIN || INT_MAX kontrolü
// {
// 	long int		sign;
// 	long int		result;

// 	result = 0;
// 	sign = 1;
// 	while (((*nptr) >= 9 && (*nptr) <= 13) || (*nptr) == 32)
// 		nptr++;
// 	if ((*nptr) == '-' || (*nptr) == '+')
// 	{
// 		if ((*nptr) == '-')
// 			sign *= -1;
// 		nptr++;
// 	}
// 	while ((*nptr) >= '0' && (*nptr) <= '9')
// 	{
// 		result = (result * 10) + ((*nptr) - 48);
// 		nptr++;
// 	}
// 	if (result * sign > INT_MAX || result * sign < INT_MIN)
// 		pexit();
// 	return ((int)result * sign);
// }

// void	args_is_int(char **av) //isdigit ve ft_strlen() > 10 kontrolü
// {
// 	int	j;
// 	int	i;

// 	i = 0;
// 	while (av[i])
// 	{
// 		j = 0;
// 		if (av[i][j] == '-' || av[i][j] == '+')
// 			j++;
// 		while (av[i][j] == '0')
// 			j++;
// 		if (ft_strlen(&av[i][j]) > 10)
// 			pexit();
// 		while (av[i][j])
// 		{
// 			if (!ft_isdigit(av[i][j]))
// 				pexit();
// 			j++;
// 		}
// 		i++;
// 	}
// }

// /*
// 	This function will combine multiple args with quote
// 	./push_swap "1 2 5 12 5" "2323 52 21" ' 23 332'  4  93
// 	to this:

// 	av[1] = "1 2 5 12 5 2323 52 21 23 332 4 93"
	
// */
// // char *compact_args(int ac, char **av)
// // {
// // 	char	*result;
// // 	int		i;
// // 	int		all_size;

// // 	i = 1;
// // 	all_size = 0;
// // 	while (i <ac)
// // 	{
// // 		all_size += ft_strlen(av[i]);
// // 		i++;
// // 	}
// // 	i = 1;
// // 	result = calloc(sizeof(char), all_size + 1 + ac -2);
// // 	if (!result)
// // 		return (NULL);
// // 	while (i < ac)
// // 	{
// // 		ft_strlcat(result, av[i], ft_strlen(result) + ft_strlen(av[i]) + 1);
// // 		if (i != ac -1)
// // 			ft_strlcat(result, " ", ft_strlen(result) + 2);
// // 		i++;
// // 	}
// // 	return (result);
// // }

// void	ft_swap(int *a, int *b)
// {
// 	int	tmp;

// 	tmp = *a;
// 	*a = *b;
// 	*b = tmp;
// }

// t_list	*new_node(int arg, int index)
// {
// 	t_list *node;

// 	node = malloc(sizeof(t_list));
// 	if (!node)
// 		pexit();
// 	node->arg = arg;
// 	node->index = index;
// 	node->next = NULL;
// 	return (node);
// }

// void	add_back(t_list **list, t_list *new)
// {
// 	t_list	*temp;

// 	if (!*list)
// 	{
// 		*list = new;
// 		return ;
// 	}
// 	temp = *list;
// 	while (temp->next)
// 		temp = temp->next;
// 	temp->next = new;
// }

// void	sort_int(int *tab, int size, t_list **list)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	ft_printf("size %d\n", size);
// 	while (i != size -1)
// 	{
// 		j = i +1;
// 		while (j <= size -1)
// 		{
// 			if (tab[i] > tab[j])
// 				ft_swap(&tab[i], &tab[j]);
// 			j++;
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while (i < size)
// 	{
// 		add_back(list, new_node(tab[i], i));
// 		i++;
// 	}
// }

// int	get_argc(char **split) // ft_strlen for double pointer
// {
// 	int	i;

// 	i = 0;
// 	if (!split)
// 		pexit();
// 	while (split[i])
// 		i++;
// 	return (i);
// }

// void	char_to_int(t_data *data, int ac, char **av)
// {
// 	int	i;

// 	i = 0;
// 	data->argc = ac -1;
// 	data->av = av;
// 	data->ac = ac;
// 	if (ac == 2)
// 	{
// 		data->argv = ft_split(av[1], ' ');
// 		if (!data->argv)
// 		pexit();
// 		data->argc = get_argc(data->argv);
// 	}
// 	else
// 		data->argv = &av[1];
// 	data->stack_a = malloc(sizeof(int) * data->argc);
// 	if (!data->stack_a)
// 		pexit();
// 	args_is_int(data->argv);
// 	while (i < data->argc)
// 	{
// 		data->stack_a[i] =  ft_atoi(data->argv[i]);
// 		i++;
// 	}
// }
// void	args_is_uniq(t_list *list)
// {
// 	t_list	*list_tmp;
// 	int		arg_tmp;

// 	arg_tmp = list->arg;
// 	list_tmp = list->next;
// 	while (list_tmp)
// 	{
// 		ft_printf("args: %d || arg+1 = %d\n", arg_tmp, list_tmp->arg);
// 		if (arg_tmp == list_tmp->arg)
// 			pexit();
// 		arg_tmp = list_tmp->arg;
// 		list_tmp = list_tmp->next;
// 	}
// }

// int	main(int ac, char **av)
// {
// 	t_data	data;
// 	t_list	*list;

// 	list = NULL;
// 	if (ac == 1)
// 		return (0);
// 	char_to_int(&data, ac, av);
// 	sort_int(data.stack_a, data.argc, &list);
// 	args_is_uniq(list);
// }


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

void	pexit(t_data *data, t_list **list)//data_list parametre alınıp data_list içinde ki alanlar freelenebilir çıkış öncesi
{
	if (data->stack_a)
		free(data->stack_a);
	if (data->stack_b)
		free(data->stack_b);
	if (*list)
		free_node(list);
	if (data->exit_status < 0)
	{
		ft_putendl_fd("Error!", 2);
		exit(EXIT_FAILURE);
	}
}
int	ft_atoi_ps(const char *nptr,t_data *data, t_list **list)//atoi ve INT_MIN || INT_MAX kontrolü
{
	long int		sign;
	long int		result;

	result = 0;
	sign = 1;
	while (((*nptr) >= 9 && (*nptr) <= 13) || (*nptr) == 32)
		nptr++;
	if ((*nptr) == '-' || (*nptr) == '+')
	{
		if ((*nptr) == '-')
			sign *= -1;
		nptr++;
	}
	while ((*nptr) >= '0' && (*nptr) <= '9')
	{
		result = (result * 10) + ((*nptr) - 48);
		nptr++;
	}
	if (result * sign > INT_MAX || result * sign < INT_MIN)
		pexit(data, list);
	return ((int)result * sign);
}

void	args_is_int(t_data *data, t_list **list) //isdigit ve ft_strlen() > 10 kontrolü
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
			pexit(data, list);
		while (data->argv[i][j])
		{
			if (!ft_isdigit(data->argv[i][j]))
				pexit(data, list);
			j++;
		}
		i++;
	}
}

/*
	This function will combine multiple args with quote
	./push_swap "1 2 5 12 5" "2323 52 21" ' 23 332'  4  93
	to this:

	av[1] = "1 2 5 12 5 2323 52 21 23 332 4 93"
	
*/
// char *compact_args(int ac, char **av)
// {
// 	char	*result;
// 	int		i;
// 	int		all_size;

// 	i = 1;
// 	all_size = 0;
// 	while (i <ac)
// 	{
// 		all_size += ft_strlen(av[i]);
// 		i++;
// 	}
// 	i = 1;
// 	result = calloc(sizeof(char), all_size + 1 + ac -2);
// 	if (!result)
// 		return (NULL);
// 	while (i < ac)
// 	{
// 		ft_strlcat(result, av[i], ft_strlen(result) + ft_strlen(av[i]) + 1);
// 		if (i != ac -1)
// 			ft_strlcat(result, " ", ft_strlen(result) + 2);
// 		i++;
// 	}
// 	return (result);
// }

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}



t_list	*new_node(int arg, int index, t_data *data, t_list **list)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	if (!node)
	{
		pexit(data, list);
	}
	node->arg = arg;
	node->index = index;
	node->next = NULL;
	return (node);
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

void	sort_int(int *tab, int size, t_data *data, t_list **list)
{
	int	i;
	int	j;

	i = 0;
	while (i != size -1)
	{
		j = i +1;
		while (j <= size -1)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < size)
	{
		add_back(list, new_node(tab[i], i, data, list));
		i++;
	}
}

int	get_argc(char **split, t_data *data, t_list **list) // ft_strlen for double pointer
{
	int	i;

	i = 0;
	if (!split)
		pexit(data, list);
	while (split[i])
		i++;
	return (i);
}

void	char_to_int(t_data *data, t_list **list)
{
	int	i;

	i = 0;
	if (data->ac == 2)
	{
		data->argv = ft_split(data->av[1], ' ');
		if (!data->argv)
			pexit(data, list);
		data->argc = get_argc(data->argv, data, list);
	}
	else
		data->argv = &data->av[1];
	data->stack_a = malloc(sizeof(int) * data->argc);
	if (!data->stack_a)
		pexit(data, list);
	args_is_int(data, list);
	while (i < data->argc)
	{
		data->stack_a[i] =  ft_atoi_ps(data->argv[i], data, list);
		i++;
	}
}

void	start_t_data(t_data *data, int ac, char **av)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->argv = NULL;
	data->argc = ac -1;
	data->av = av;
	data->ac = ac;
	data->exit_status = -1;
}
void	args_is_uniq(t_data *data, t_list **list)
{
	t_list	*list_tmp;
	int		arg_tmp;

	arg_tmp = (*list)->arg;
	list_tmp = (*list)->next;
	while (list_tmp)
	{
		if (arg_tmp == list_tmp->arg)
			pexit(data, list);
		arg_tmp = list_tmp->arg;
		list_tmp = list_tmp->next;
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	t_list	*list;

	list = NULL;
	start_t_data(&data, ac, av);
	char_to_int(&data, &list);
	sort_int(data.stack_a, data.argc, &data, &list);
	args_is_uniq(&data, &list);
	data.exit_status = 1;
	int i = 0;
	while (i < data.argc)
	{
		ft_printf("%d", data.stack_a[i]);
		if (i +1 != data.argc)
			ft_printf(" ");
		else
			ft_printf("\n");
		i++;
	}
	pexit(&data, &list);
}
