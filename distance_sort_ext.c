/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_sort_ext.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:15:35 by njackson          #+#    #+#             */
/*   Updated: 2024/04/17 16:51:32 by njackson         ###   ########.fr       */
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
	t_stack	*check;
	t_stack	*before;
	t_stack	*after;
	int		r_dir;

	/*DEBUG*/ft_printf_fd(2, "CHECKING pa\n");
	if (ft_lstsize(s_b) < 3)
		return (0);
	before = s_b->content;
	while (s_b->next->next)
		s_b = s_b->next;
	after = s_b->content;
	check = s_b->next->content;
	if (check->dist < 0)
		return (1);
	if (before->fi + 1 == check->fi || check->fi + 1 == after->fi)
		return (0);
	r_dir = (ft_lstsize(s_b) - n_pos) > n_pos;
	if (a->dist != 0 && r_dir)
		n_pos = find_touch_stack(s_b, a->fi, 0, n_pos);
	else if (a->dist != 0)
		n_pos = find_touch_stack(s_b, a->fi, n_pos, ft_lstsize(s_b));
	/*DEBUG*/ft_printf_fd(2, "RUNNING IF\n");
	if ((r_dir && (find_touch_stack(s_b, check->fi, 0, n_pos) >= 0)) ||
		(!r_dir && (find_touch_stack(s_b, check->fi, n_pos, ft_lstsize(s_b)) >= 0)))
	{
		/*DEBUG*/ft_printf_fd(2, "PICKING pa\n");
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

int	find_touch_stack(t_list *s_b, int f, int s, int e)
{
	t_stack	*cont;
	int 	i;

	i = 0;
	/*DEBUG*/ft_printf_fd(2, "BEGGINING LOOP\n");
	while (i++ < s && s_b)
		s_b = s_b->next;
	/*DEBUG*/ft_printf_fd(2, "STARTING CHECKS %d\n", i);
	while (i < e && s_b)
	{
		cont = s_b->content;
		if (cont->fi == f + 1 || cont->fi == f - 1)
		{
			/*DEBUG*/ft_printf_fd(2, "RETURNING %d\n", i);
			return (i);
		}
		s_b = s_b->next;
		i++;
	}
	/*DEBUG*/ft_printf_fd(2, "NOT FOUND BETWEEN %d AND %d -- %d\n", s, e, i);
	return (-1);
}
