/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:04:21 by njackson          #+#    #+#             */
/*   Updated: 2024/04/25 21:42:02 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solver.h"

static int	get_max(t_list *s_a)
{
	t_stack	*cont;
	int		max;

	max = -1;
	while (s_a)
	{
		cont = s_a->content;
		if (max < cont->fi)
			max = cont->fi;
		s_a = s_a->next;
	}
	return (max);
}

static int	get_init_range(int n, int a)
{
	int		out;

	out = 0;
	out = ft_log_base_n(n, 2);
	out *= out;
	return ((out >> 2) + a);
}

//#include <stdio.h>
//#include "stack_printer.c"

void	initial_sort(t_list **s_a, t_list **s_b,
	t_list **instr_lst, char **instrs)
{
	t_stack	*stack;
	int		range;
	int		add_range;

	add_range = ft_lstsize(*s_a) / 60;
	while (ft_lstsize(*s_a) > 3)
	{
		stack = ft_lstlast(*s_a)->content;
		range = get_init_range(get_max(*s_a), add_range);
		if (ft_lstsize(*s_a) - stack->fi <= range && stack->fi > 2)
			record_instr(instrs[9], s_a, s_b, instr_lst);
		else
			record_instr(instrs[3], s_a, s_b, instr_lst);
	}
}
//		/*DEBUG*/print_stacks(*s_a, *s_b);
//		/*DEBUG*/ft_printf_fd(2, "PICKED INSTRUCTION %s\n", instrs[instr_i]);
//		/*DEBUG*/ft_printf_fd(2, "<<BREAK POINT>>"); getchar();
