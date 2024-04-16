/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_sort_ext.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:15:35 by njackson          #+#    #+#             */
/*   Updated: 2024/04/16 16:15:39 by njackson         ###   ########.fr       */
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

int	rotate_direction(t_list *s_b)
{
	t_list	*next;
	t_stack	*tmp;
	t_stack	*least;

	least = s_b->content;
	next = s_b->next;
	while (next)
	{
		tmp = next->content;
		if (tmp->fi < least->fi)
			least = tmp;
		next = next->next;
	}
	return (-least->dist > ft_lstsize(s_b) / 2);
}
