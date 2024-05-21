/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:04:21 by njackson          #+#    #+#             */
/*   Updated: 2024/05/21 16:20:59 by njackson         ###   ########.fr       */
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
	return ((out / 8) + a);
}

void	init_marker(t_list *s_a, int *marker)
{
	marker[3] = ft_lstsize(s_a);
	marker[0] = marker[3] / 2;
	marker[1] = marker[3] / 2;
	marker[2] = marker[3] / 2;
	marker[5] = marker[3] / 60 + 1;
}

//#include <stdio.h>
//#include "stack_printer.c"

void	initial_sort(t_list **s_a, t_list **s_b,
	t_list **instr_lst, char **instrs)
{
	t_stack	*stack;
	int		marker[6];

	init_marker(*s_a, marker);
	while (marker[3] > 3)
	{
		stack = ft_lstlast(*s_a)->content;
		marker[4] = get_init_range(get_max(*s_a), marker[5]);
		if (stack->fi > 2
			&& stack->fi >= marker[2] && stack->fi <= marker[0] + marker[4])
		{
			record_instr(instrs[9], s_a, s_b, instr_lst);
			marker[0]++;
		}
		else if (stack->fi > 2
			&& stack->fi <= marker[2] && stack->fi >= marker[1] - marker[4])
		{
			record_instr(instrs[9], s_a, s_b, instr_lst);
			record_instr(instrs[4], s_a, s_b, instr_lst);
			marker[1]--;
		}
		else
			record_instr(instrs[3], s_a, s_b, instr_lst);
		marker[3] = ft_lstsize(*s_a);
	}
}
//		/*DEBUG*/ft_printf_fd(2, "PICKED INSTRUCTION %s\n", instrs[instr_i]);

//		/*DEBUG*/print_stacks(*s_a, *s_b);
//		/*DEBUG*/ft_printf_fd(2, "LAST INSTR: %s\n",
//			ft_lstlast(*instr_lst)->content);
//		/*DEBUG*/ft_printf_fd(2, "RANGE: %d\n", marker[4]);
//		/*DEBUG*/ft_printf_fd(2, "MARKERS: %d, %d\n", marker[0], marker[1]);
//		/*DEBUG*/ft_printf_fd(2, "<<BREAK POINT>>"); getchar();
