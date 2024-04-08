/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distances_ext.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:18:38 by njackson          #+#    #+#             */
/*   Updated: 2024/04/08 21:33:58 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solver.h"

int	sa_change(t_list *s)
{
	int		total;
	t_stack	*top;
	t_stack	*sec;

	if (ft_lstsize(s) < 2)
		return (-2048);
	while (s->next->next)
		s = s->next;
	top = s->next->content;
	sec = s->content;
	total = 0;
	if (top->dist < 0)
		total++;
	else
		total--;
	if (sec->dist > 0)
		total++;
	else
		total--;
	return (total);
}

int	sb_change(t_list *s)
{
	int		total;
	t_stack	*top;
	t_stack	*sec;

	if (ft_lstsize(s) < 2)
		return (-2048);
	while (s->next->next)
		s = s->next;
	top = s->next->content;
	sec = s->content;
	total = 0;
	if (top->dist > 0)
		total++;
	else
		total--;
	if (sec->dist < 0)
		total++;
	else
		total--;
	return (total);
}

int	stack_entropy(t_list *s)
{
	t_stack	*cont;
	int		total;

	total = 0;
	while (s)
	{
		cont = s->content;
		total += ft_abs(cont->dist);
		s = s->next;
	}
	return (total);
}

int	check_solved(t_list *s_a, t_list *s_b)
{
	if (s_b)
		return (0);
	if (stack_entropy(s_a))
		return (0);
	return (1);
}

void	get_changes(t_list *s_a, t_list *s_b, int *changes)
{
	changes[0] = sa_change(s_a);
	changes[1] = sb_change(s_b);
	changes[2] = changes[0] + changes[1];
	changes[3] = ra_change(s_a);
	changes[4] = rb_change(s_b);
	changes[5] = changes[3] + changes[4];
	changes[6] = rra_change(s_a);
	changes[7] = rrb_change(s_b);
	changes[8] = changes[6] + changes[7];
}
