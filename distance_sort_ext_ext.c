/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_sort_ext2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:31:43 by njackson          #+#    #+#             */
/*   Updated: 2024/04/18 12:54:54 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solver.h"

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
		return (0);
	return (1);
}
