/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solver.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:28:41 by njackson          #+#    #+#             */
/*   Updated: 2024/05/07 15:06:11 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_SOLVER_H
# define PUSH_SWAP_SOLVER_H

# include "push_swap.h"
# include "libft.h"

typedef struct s_imap
{
	int	v;
	int	oi;
}	t_imap;

typedef struct s_stack
{
	int	fi;
	int	dist;
}	t_stack;

int		*index_arr(int *arr, int size);
int		check_dups(int *arr, int size);
t_list	*init_stack_a(int *arr, int size);
void	output_instr(t_list *instr);

void	cutdown_instr(t_list **instr_lst);
int		ps_solver_error(int *arr);

// distance sort funcs
t_list	*distance_sort(t_list *s_a);

char	**get_instr_arr(void);

void	record_instr(char *instr, t_list **s_a,
			t_list **s_b, t_list **instr_lst);

int		stack_in_order(t_list *s);
int		next_position(t_list *s_b);
//int		find_touch_stack(t_list *s_b, int f, int s, int e);

int		is_top_in_group(t_list *s_b);

// initial sort
void	initial_sort(t_list **s_a, t_list **s_b,
			t_list **instr_lst, char **instrs);

// return sort
void	return_sort(t_list **s_a, t_list **s_b,
			t_list **instr_lst, char **instrs);

// distance functions
void	get_distances(t_list **s_a, t_list **s_b);
int		stack_entropy(t_list *s);
int		check_solved(t_list *s_a, t_list *s_b);

// quicksort functions
int		partition(t_imap *arr, int start, int end);
t_imap	*quicksort(t_imap *arr, int start, int end);

#endif
