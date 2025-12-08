/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kedemiro <kedemiro@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:11:41 by kedemiro          #+#    #+#             */
/*   Updated: 2025/12/06 15:00:11 by kedemiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./sources/libft.h" 
# include "limits.h"

typedef struct s_list
{
	int				arg;
	int				index;

	struct s_list	*next;
}	t_list;

typedef struct s_data
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

}	t_data;

t_list	*doppelganger(t_data *data);
t_list	*new_node(int arg, int index, t_data *data);
void	swap_a(t_data *data);
void	push_a(t_data *data);
void	push_b(t_data *data);
void	sort_int(t_data *data);
void	rotate_a(t_data *data);
void	all_free(char **split);
void	ft_swap(int *a, int *b);
void	free_node(t_list **list);
void	null_check(t_data *data);
void	under_nine(t_data *data);
void	radix_sort(t_data *data);
void	args_is_int(t_data *data);
void	char_to_int(t_data *data);
void	reverse_rotate_a(t_data *data);
void	pexit(t_data *data, int exit_status);
void	add_back(t_list **list, t_list *new);
void	arg_to_index(t_data *data, t_list *copy);
void	arg_is_uniq(t_data *data, t_list **copy);
void	bring_to_top(t_data *data, int target_index);
void	start_t_data(t_data *data, int ac, char **av);
int		find_msb(t_data *data);
int		get_argc(t_data *data);
int		line_len(const char *s);
int		count_node(t_data *data);
int		compact_args(t_data *data);
int		ft_atoi_ps(t_data *data, int i);
int		is_already_sorted(t_data *data);
int		get_position(t_data *data, int target_index);

#endif