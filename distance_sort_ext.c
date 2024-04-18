/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_sort_ext.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:15:35 by njackson          #+#    #+#             */
/*   Updated: 2024/04/18 12:11:36 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solver.h"

int	stack_in_order(t_list *s)
{
	t_stack	*a;
	t_stack	*b;

	while (s && s->next)
	{
		a = s->content;
		b = s->next->content;
		if (a->fi > b->fi)
			return (0);
		s = s->next;
	}
	return (1);
}

int	do_push_a(t_list *s_b, t_stack *a, int n_pos)
{
	t_list	*t_b;
	t_stack	*check;
	t_stack	*before;
	t_stack	*after;
	int		r_dir;

	t_b = s_b;
	if (ft_lstsize(t_b) < 3 || n_pos == ft_lstsize(s_b) / 2)
		return (0);
	before = t_b->content;
	while (t_b->next->next)
		t_b = t_b->next;
	after = t_b->content;
	check = t_b->next->content;
	if (before->fi + 1 == check->fi || check->fi + 1 == after->fi)
		return (0);
	r_dir = (ft_lstsize(s_b) - n_pos) > n_pos;
	n_pos = find_touch_stack(s_b, a->fi, 0, n_pos);
	if (n_pos < 0)
		return (0);
	if ((r_dir && (find_touch_stack(s_b, check->fi, 2, n_pos) >= 0)) ||
		(!r_dir && (find_touch_stack(s_b, check->fi, n_pos + 1, ft_lstsize(s_b)) >= 0)))
		return (1);
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

int	next_position(t_list *s_b)
{
	t_list	*next;
	t_stack	*tmp;
	t_stack	*least;
	int		curr_i;
	int		least_i;

	least = s_b->content;
	least_i = 0;
	next = s_b->next;
	curr_i = 1;
	while (next)
	{
		tmp = next->content;
		if (tmp->fi < least->fi)
		{
			least = tmp;
			least_i = curr_i;
		}
		next = next->next;
		curr_i++;
	}
	return (least_i);
}


#include <stdio.h>

int	find_touch_stack(t_list *s_b, int f, int s, int e)
{
	t_stack	*cont;
	int 	i;

	i = -1;
	while (++i < s && s_b)
		s_b = s_b->next;
//	/*DEBUG*/ft_printf_fd(2, "CHECKING FOR: %d +- 1 BETWEEN: %d : %d\n", f, s, e);
	while (i < e && s_b)
	{
		cont = s_b->content;
		if (cont->fi == f + 1 || cont->fi == f - 1)
		{
//			/*DEBUG*/ft_printf_fd(2, "FOUND %d AT: %d\n", cont->fi, i);
//			/*DEBUG*/getchar();
			return (i);
		}
		s_b = s_b->next;
		i++;
	}
	return (-1);
}
