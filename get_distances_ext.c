/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distances_ext.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:18:38 by njackson          #+#    #+#             */
/*   Updated: 2024/04/06 16:43:23 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solver.h"

int	sa_change(t_list *s)
{
	int		total;
	t_stack	top;
	t_stack	sec;

	if (ft_lstsize(s) < 2)
		return (-2048);
	while (s->next->next)
		s = s->next;
	top = s->next->content;
	sec = s->content;
	total = 0;
	if (top < 0)
		total++;
	else
		total--;
	if (sec > 0)
		total++;
	else
		total--;
	return (total);
}

int	sb_change(t_list *s)
{
	int		total;
	t_stack	top;
	t_stack	sec;

	if (ft_lstsize(s) < 2)
		return (-2048);
	while (s->next->next)
		s = s->next;
	top = s->next->content;
	sec = s->content;
	total = 0;
	if (top > 0)
		total++;
	else
		total--;
	if (sec < 0)
		total++;
	else
		total--;
	return (total);
}
