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


#include <stdio.h> /*DEBUG*/

int	return_instr(t_list *s_a, t_list *s_b)
{
	t_stack	*last_a;
	t_stack	*last_b;
	int		change;

	if (!s_b)
		return (0);
	last_a = ft_lstlast(s_a)->content;
	last_b = ft_lstlast(s_b)->content;
	if (sb_change(s_b) > 0 && last_a->dist < 0)
		return (2);
	if (last_a->dist < 0)
		return (0);
	change = next_position(s_b);
	if (change == ft_lstsize(s_b))
		return (1);
	if ((last_a->dist == 0 && last_b->dist == 0)
		|| do_push_a(s_b, last_a, change))
		return (10);
	if (do_push_b(s_b, last_a))
		return (9);
	if (sb_change(s_b) > 0 && !is_top_in_group(s_b))
		return (1);
	if ((ft_lstsize(s_b) - change) > change)
		return (7);
	return (4);
}

void	return_sort(t_list **s_a, t_list **s_b, t_list **instr_lst, char **instrs)
{
	int	instr_i;

	instr_i = -1;
	get_distances(s_a, s_b);
	while (!check_solved(*s_a, *s_b))
	{
		instr_i = return_instr(*s_a, *s_b);
//		/*DEBUG*/print_stacks(*s_a, *s_b);
//		/*DEBUG*/ft_printf_fd(2, "PICKED INSTR: %s\n", instrs[instr_i]);
//		/*DEBUG*/ft_printf_fd(2, "<<BREAK POINT>>"); getchar();
		record_instr(instrs[instr_i], s_a, s_b, instr_lst);
	}
}
