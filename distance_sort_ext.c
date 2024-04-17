/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_sort_ext.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:15:35 by njackson          #+#    #+#             */
/*   Updated: 2024/04/17 13:24:51 by njackson         ###   ########.fr       */
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

int	do_push_a(t_list *s_b, t_stack *a, int r_dir)
{
	t_stack	*check;
	t_stack	*before;
	t_stack	*after;

	(void)r_dir;
	if (ft_lstsize(s_b) < 3)
		return (0); // 1 or 2 operation save here?
	before = s_b->content;
	while (s_b->next->next)
		s_b = s_b->next;
	after = s_b->content;
	check = s_b->next->content;
	if (check->dist < 0)
		return (1);
	if (before->fi + 1 == check->fi || check->fi + 1 == after->fi)
		return (0);
	if (a->dist == 0)
	{
		
	}
	return (0);
}

int	do_push_b(t_list *s_b, t_stack *a, int r_dir)
{
	t_list	*tmp;
	t_stack	*before;
	t_stack	*after;

	(void)r_dir;
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
	return (curr_i);
}
