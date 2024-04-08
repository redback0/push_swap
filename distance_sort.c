/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:06:01 by njackson          #+#    #+#             */
/*   Updated: 2024/04/08 21:52:09 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solver.h"

static char	**get_instr_arr(void)
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
	t_list	*instr_lst[2];
	int		instr_i;

	s_b = 0;
	instr_lst[0] = 0;
	instrs = get_instr_arr();
	get_distances(&s_a, &s_b);
	while (!check_solved(s_a, s_b))
	{
		get_changes(s_a, s_b, changes);
		instr_i = ft_arrmax(changes, 9);
		ft_printf_fd(2, "SELECTING INSTRUCTION %s WITH ENTROPY %d\n", instrs[instr_i], changes[instr_i]);
		do_instr(instrs[instr_i], &s_a, &s_b);
		instr_lst[1] = ft_lstnew(instrs[instr_i]);
		if (!instr_lst[0])
			instr_lst[0] = instr_lst[1];
		instr_lst[1] = instr_lst[1]->next;
		get_distances(&s_a, &s_b);
	}
	free(instrs);
	return (instr_lst[0]);
}
