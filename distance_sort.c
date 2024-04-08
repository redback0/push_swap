/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:06:01 by njackson          #+#    #+#             */
/*   Updated: 2024/04/08 17:16:23 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solver.h"

static char	**get_instr_arr()
{
	char	**out;

	out = (char **)malloc(9 * sizeof(char *));
	out[0] = ft_strdup("sa");
	out[1] = ft_strdup("sb");
	out[2] = ft_strdup("ss");
	out[3] = ft_strdup("ra");
	out[4] = ft_strdup("rb");
	out[5] = ft_strdup("rr");
	out[6] = ft_strdup("rra");
	out[7] = ft_strdup("rrb");
	out[8] = ft_strdup("rrr");
	return (out);
}

t_list	*distance_sort(t_list *s_a)
{
	t_list	*s_b;
	int		changes[9];
	char	**instrs;
	t_list	*instr_start;
	t_list	*instr_end;

	instrs = get_instr_arr();
	while (!check_solved(s_a, s_b))
	{
		get_distances(&s_a, &s_b);
		get_changes(s_a, s_b, changes);
		
		if (!instr_start)
			instr_start = instr_end;
		instr_end = instr_end->next;
	}
	return (*instr_start);
}
