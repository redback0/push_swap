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
	if (s_b || stack_entropy(s_a))
		return (0);
	return (1);
}
