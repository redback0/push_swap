/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distances.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:56:44 by njackson          #+#    #+#             */
/*   Updated: 2024/04/15 12:54:28 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solver.h"

void	get_distances(t_list **s_a, t_list **s_b)
{
	t_list	*lst;
	t_stack	*cont;
	int		a_len;
	int		b_len;
	int		i;

	a_len = ft_lstsize(*s_a);
	b_len = ft_lstsize(*s_b);
	i = 0;
	lst = *s_a;
	while (i < a_len)
	{
		cont = (t_stack *)lst->content;
		cont->dist = cont->fi - i++;
		lst = lst->next;
	}
	i = a_len + b_len - 1;
	lst = *s_b;
	while (i >= a_len)
	{
		cont = (t_stack *)lst->content;
		cont->dist = cont->fi - i--;
		lst = lst->next;
	}
}

int	ra_change(t_list *s)
{
	t_stack	*cont;
	int		total;

	if (!s || ft_lstsize(s) < 3)
		return (-1);
	total = 0;
	while (s->next)
	{
		cont = s->content;
		if (cont->dist > 0)
			total++;
		else if (ft_lstsize(s) != 2)
			total--;
		s = s->next;
	}
	cont = s->content;
	total += (ft_abs(cont->dist) - cont->fi);
	return (total);
}

int	rra_change(t_list *s)
{
	t_stack	*cont;
	int		total;
	int		new_dist;

	if (!s || ft_lstsize(s) < 3)
		return (-1);
	cont = s->content;
	new_dist = cont->fi - (ft_lstsize(s) - 1);
	total = (cont->dist - ft_abs(new_dist));
	s = s->next;
	while (s)
	{
		cont = s->content;
		if (cont->dist < 0)
			total++;
		else if (ft_lstsize(s) != 1)
			total--;
		s = s->next;
	}
	return (total);
}

int	rb_change(t_list *s)
{
	t_stack	*cont;
	int		total;
	int		new_dist;

	if (!s || ft_lstsize(s) < 3)
		return (-1);
	total = 0;
	while (s->next)
	{
		cont = s->content;
		if (cont->dist < 0)
			total++;
		else if (ft_lstsize(s) != 2)
			total--;
		s = s->next;
	}
	cont = s->content;
	new_dist = cont->dist - (ft_lstsize(s) - 1);
	total += (ft_abs(cont->dist) - ft_abs(new_dist));
	return (total);
}

int	rrb_change(t_list *s)
{
	t_stack	*cont;
	int		total;
	int		new_dist;

	if (!s || ft_lstsize(s) < 3)
		return (-1);
	cont = s->content;
	new_dist = cont->dist + (ft_lstsize(s) - 1);
	total = (ft_abs(cont->dist) - ft_abs(new_dist));
	s = s->next;
	while (s)
	{
		cont = s->content;
		if (cont->dist > 0)
			total++;
		else if (ft_lstsize(s) != 1)
			total--;
		s = s->next;
	}
	return (total);
}
