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
	char	*before_split;
	int		argc;
	int		ac;
	int		exit_status;
	int		max_bit;
	int		node_count;
	int		allocated;
	t_list	*stack_a;
	t_list	*stack_b;

}t_data;

#endif