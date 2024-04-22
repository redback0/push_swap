/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:59:27 by njackson          #+#    #+#             */
/*   Updated: 2024/04/22 12:59:29 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solver.h"

static void	return_instr(t_list **s_a, t_list **s_b,
	t_list **instr_lst, char **instrs)
{
	static int	on_bot = 0;
	t_stack		*stacks[3];
	int			n_pos;

	stacks[0] = (*s_a)->content;
	stacks[1] = ft_lstlast(*s_a)->content;
	if (*s_b)
		stacks[2] = ft_lstlast(*s_b)->content;
	n_pos = next_position(*s_b);
	if (on_bot && stacks[0]->fi == stacks[1]->fi + 1)
	{
		on_bot--;
		record_instr(instrs[6], s_a, s_b, instr_lst); // rra
	}
	else if (n_pos == ft_lstsize(*s_b) - 1)
		record_instr(instrs[10], s_a, s_b, instr_lst); // pa, in place
	else if (!on_bot || stacks[0]->fi > stacks[2]->fi)
	{
		on_bot++;
		record_instr(instrs[10], s_a, s_b, instr_lst); // pa, ra
		record_instr(instrs[3], s_a, s_b, instr_lst);
	}
	record_instr(instrs[4 + ((ft_lstsize(*s_b) - n_pos) > n_pos) * 3],
		s_a, s_b, instr_lst); // rb
}

//#include "stack_printer.c"
#include <stdio.h> /*DEBUG*/

void	return_sort(t_list **s_a, t_list **s_b,
	t_list **instr_lst, char **instrs)
{
	get_distances(s_a, s_b);
	while (!check_solved(*s_a, *s_b))
	{
//		/*DEBUG*/print_stacks(*s_a, *s_b);
//		/*DEBUG*/ft_printf_fd(2, "<<BREAK POINT>>"); getchar();
		return_instr(s_a, s_b, instr_lst, instrs);
	}
}
