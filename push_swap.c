#include "push_swap.h"
#include <stdio.h>

void	pexit(/*add pointers needs to be free*/)
{
	ft_putendl_fd("Error!", 2);
	exit(EXIT_FAILURE);
}
int	ft_atoi(const char *nptr)//atoi ve INT_MIN || INT_MAX kontrolü
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
		pexit();
	return ((int)result * sign);
}

void	args_is_int(char **av, int  i) //isdigit ve ft_strlen() > 10 kontrolü
{
	int	j;

	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (av[i][j] == '0')
			j++;
		if (ft_strlen(&av[i][j]) > 10)
			pexit();
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				pexit();
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

void	index_sort(int a[], int ac)
{
	int *a;
	int	*b;


}

int	get_argc(char **split) // ft_strlen for double pointer
{
	int	i;

	i = 0;
	if (!split)
		return (-1);
	while (split[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int 	i;
	char	**args;
	int		argc;

	i = 1;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!args)
			return (0);
		ac = get_argc(args);
		i--;
	}
	args_is_int(args, i);
	while (i < ac)
	{
		ft_printf("%d\n", ft_atoi(args[i]));
		i++;
	}
}
