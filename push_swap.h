#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "./sources/libft.h" 
# include "limits.h"

typedef struct s_list
{
	int arg;
	int index;

	struct s_list *next;
	
}t_list;

typedef struct	s_data
{
	char	**argv;
	char	**av;
	int		argc;
	int		ac;
	int		*stack_a;
	int		*stack_b;
	int		exit_status;

}t_data;

#endif