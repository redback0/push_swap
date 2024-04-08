/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solver.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:28:41 by njackson          #+#    #+#             */
/*   Updated: 2024/04/08 15:33:05 by njackson         ###   ########.fr       */
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

t_list	*distance_sort(t_list *s_a);

// distance functions
void	get_distances(t_list **s_a, t_list **s_b);

int		ra_change(t_list *s);
int		rb_change(t_list *s);
int		rra_change(t_list *s);
int		rrb_change(t_list *s);

int		sa_change(t_list *s);
int		sb_change(t_list *s);
int		stack_entropy(t_list *s);

int		check_solved(t_list *s_a, t_list *s_b);
void	get_changes(t_list *s_a, t_list *s_b, int *changes);

// quicksort functions
int		partion(t_imap *arr, int start, int end);
t_imap	*quicksort(t_imap *arr, int start, int end);

#endif
