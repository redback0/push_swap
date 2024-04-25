/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:04:21 by njackson          #+#    #+#             */
/*   Updated: 2024/04/25 18:43:41 by njackson         ###   ########.fr       */
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

static int	get_init_range(int n)
{
	int		out;

	out = 0;
	while (n)
	{
		n = n >> 1;
		out++;
	}
	out *= out;
	return ((out >> 2) + 1);
}

static int	*get_first_last(t_list *s_a, int *out)
{
	t_stack	*cont;
	int		max;
	int		range;
	int		i;

	max = get_max(s_a);
	range = get_init_range(max);
	out[0] = -1;
	out[1] = -1;
	i = 0;
	while (s_a)
	{
		cont = s_a->content;
		if (max - cont->fi < range)
		{
			if (out[0] < 0)
				out[0] = i;
			out[1] = i;
		}
		s_a = s_a->next;
		i++;
	}
	return (out);
}

// I hate this function :/
static void	init_rotator(t_list **s_a, t_list **s_b,
	t_list **instr_lst, char **instrs)
{
	int		size;
	int		*fl_no;

	size = ft_lstsize(*s_a);
	fl_no = (int *)malloc(2 * sizeof(int));
	get_first_last(*s_a, fl_no);
	if (size - fl_no[1] < fl_no[0])
		record_instr(instrs[3], s_a, s_b, instr_lst);
	else
		record_instr(instrs[6], s_a, s_b, instr_lst);
	free(fl_no);
}

//#include <stdio.h>
//#include "stack_printer.c"

void	initial_sort(t_list **s_a, t_list **s_b,
	t_list **instr_lst, char **instrs)
{
	t_stack	*stack;
	int		size;
	int		range;

	while (ft_lstsize(*s_a) > 3)
	{
		stack = ft_lstlast(*s_a)->content;
		size = ft_lstsize(*s_a);
		range = get_init_range(get_max(*s_a));
		if (size - stack->fi <= range && stack->fi > 2)
			record_instr(instrs[9], s_a, s_b, instr_lst);
		else
			init_rotator(s_a, s_b, instr_lst, instrs);
	}
}
//		/*DEBUG*/print_stacks(*s_a, *s_b);
//		/*DEBUG*/ft_printf_fd(2, "PICKED INSTRUCTION %s\n", instrs[instr_i]);
//		/*DEBUG*/ft_printf_fd(2, "<<BREAK POINT>>"); getchar();
