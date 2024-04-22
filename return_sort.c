/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:59:27 by njackson          #+#    #+#             */
/*   Updated: 2024/04/22 12:59:29 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solver.h"


#include <stdio.h> /*DEBUG*/

int	do_push_a(t_list *s_b, t_stack *a, int n_pos)
{
	t_list	*t_b;
	t_stack	*check;
	int		r_dir;

	(void)a;
	t_b = s_b;
	if (ft_lstsize(t_b) < 3 || n_pos == ft_lstsize(s_b) / 2)
		return (0);
	if (is_top_in_group(s_b))
		return (0);
	while (t_b->next)
		t_b = t_b->next;
	check = t_b->content;
	r_dir = (ft_lstsize(s_b) - n_pos) > n_pos;
//	n_pos = find_touch_stack(s_b, a->fi, 0, ft_lstsize(s_b) + 1);
	if (n_pos < 0)
		return (0);
	if ((r_dir && (find_touch_stack(s_b, check->fi, 2, n_pos) >= 0)) ||
		(!r_dir && (find_touch_stack(s_b, check->fi, n_pos + 1,
		ft_lstsize(s_b)) >= 0)))
	{
		/*DEBUG*/ft_printf_fd(2, "ADDING NONE ORDERED TO A\n");
		return (1);
	}
	return (0);
}

int	do_push_b(t_list *s_b, t_stack *a)
{
	t_list	*tmp;
	t_stack	*before;
	t_stack	*after;

	if (ft_lstsize(s_b) < 2)
		return (0);
	tmp = s_b;
	while (tmp->next->next)
		tmp = tmp->next;
	before = s_b->content;
	after = tmp->next->content;
	if (before->fi + 1 == a->fi || a->fi + 1 == after->fi)
	{
//		/*DEBUG*/ft_printf_fd(2, "PUSHING B\n");
		return (1);
	}
	return (0);
}

static void	return_instr(t_list **s_a, t_list **s_b,
	t_list **instr_lst, char **instrs)
{
	t_stack	*last_a;
	t_stack	*last_b;
	int		change;

	if (!*s_b)
		record_instr(instrs[0], s_a, s_b, instr_lst);
	else
	{
		last_a = ft_lstlast(*s_a)->content;
		last_b = ft_lstlast(*s_b)->content;
		if (sb_change(*s_b) > 0 && last_a->dist < 0)
			record_instr(instrs[2], s_a, s_b, instr_lst);
		else if (last_a->dist < 0)
			record_instr(instrs[0], s_a, s_b, instr_lst);
		else
		{
			change = next_position(*s_b);
			if (change == ft_lstsize(*s_b))
				record_instr(instrs[1], s_a, s_b, instr_lst);
			else if ((last_a->dist == 0 && last_b->dist == 0)
				|| do_push_a(*s_b, last_a, change))
				record_instr(instrs[10], s_a, s_b, instr_lst);
			else if (do_push_b(*s_b, last_a))
				record_instr(instrs[9], s_a, s_b, instr_lst);
//			else if (sb_change(*s_b) > 0 && !is_top_in_group(*s_b))
//				record_instr(instrs[1], s_a, s_b, instr_lst);
			else if ((ft_lstsize(*s_b) - change) > change)
				record_instr(instrs[7], s_a, s_b, instr_lst);
			else
				record_instr(instrs[4], s_a, s_b, instr_lst);
		}
	}
}


void	print_stacks(t_list *s_a, t_list *s_b); // DEBUG FUNC

void	return_sort(t_list **s_a, t_list **s_b,
	t_list **instr_lst, char **instrs)
{
	t_stack	*s_first;
	t_stack	*s_last;

	get_distances(s_a, s_b);
	while (!check_solved(*s_a, *s_b))
	{
		/*DEBUG*/print_stacks(*s_a, *s_b);
		return_instr(s_a, s_b, instr_lst, instrs);
		/*DEBUG*/ft_printf_fd(2, "<<BREAK POINT>>"); getchar();
		s_first = (*s_a)->content;
		s_last = ft_lstlast(*s_a)->content;
		while (s_first->fi - 1 == s_last->fi)
		{
			record_instr(instrs[6], s_a, s_b, instr_lst);
			s_first = (*s_a)->content;
			s_last = ft_lstlast(*s_a)->content;
		}
	}
}
