#include "push_swap.h"
#include <stdio.h>

int	ft_atoi(const char *nptr)
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
	return ((int)result * sign);
}
void	pexit()
{
	ft_putendl_fd("Error!", 2);
	exit(EXIT_FAILURE);
}

void	get_list(char	**av)
{
	
}

void	args_is_int(char **av)
{
	int	i ;
	int	j;

	i = 1;
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

int	main(int ac, char **av)
{
	int i = 1;
	while (av[i])
	{
		args_is_int(av);
		ft_printf("%d\n", ft_atoi(av[i]));
		i++;
	}
}
