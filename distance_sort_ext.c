/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_sort_ext.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:15:35 by njackson          #+#    #+#             */
/*   Updated: 2024/04/18 12:53:38 by njackson         ###   ########.fr       */
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

int	next_position(t_list *s_b)
{
	t_list	*next;
	t_stack	*tmp;
	t_stack	*least;
	int		curr_i;
	int		least_i;

	if (!s_b)
		return (-1);
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

// THIS FUNCTION IS CURRENTLY UNUSED
int	find_touch_stack(t_list *s_b, int f, int s, int e)
{
	t_stack	*cont;
	int		i;

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
			return (i);
		}
		s_b = s_b->next;
		i++;
	}
//	/*DEBUG*/ft_printf_fd(2, "NOT FOUND BEFORE %d\n", i);
	return (-1);
}

// THIS FUNCTION IS CURRENTLY UNUSED
int	is_top_in_group(t_list *s_b)
{
	t_stack	*before;
	t_stack	*after;
	t_stack	*check;

	before = s_b->content;
	while (s_b->next->next)
		s_b = s_b->next;
	after = s_b->content;
	check = s_b->next->content;
	if (before->fi + 1 == check->fi || check->fi + 1 == after->fi)
		return (1);
	return (0);
}
