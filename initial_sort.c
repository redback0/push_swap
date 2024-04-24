/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:04:21 by njackson          #+#    #+#             */
/*   Updated: 2024/04/24 14:04:23 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solver.h"

static int	get_init_range(t_list *s_a)
{
	t_stack	*cont;
	int		max;
	int		out;

	max = -1;
	while (s_a)
	{
		cont = s_a->content;
		if (max < cont->fi)
			max = cont->fi;
		s_a = s_a->next;
	}
	out = 0;
	while (max)
	{
		max = max >> 1;
		out++;
	}
	out *= out;
	return ((out >> 2) + 1);
}

// I hate this function :/
static void	init_rotator(t_list **s_a, t_list **s_b,
	t_list **instr_lst, char **instrs)
{
	t_list	*tmp;
	t_stack	*cont;
	int		size;
	int		first;
	int		last;
	int		range;
	int		i;

	tmp = *s_a;
	size = ft_lstsize(tmp);
	range = get_init_range(*s_a);
	first = -1;
	last = -1;
	i = 0;
	while (tmp)
	{
		cont = tmp->content;
		if (size - cont->fi < range)
		{
			if (first < 0)
				first = i;
			last = i;
		}
		tmp = tmp->next;
		i++;
	}
	if (size - last < first)
		record_instr(instrs[3], s_a, s_b, instr_lst);
	else
		record_instr(instrs[6], s_a, s_b, instr_lst);
}

static void	initial_instr(t_list **s_a, t_list **s_b,
	t_list **instr_lst, char **instrs)
{
	t_stack	*stack;
	int		size;
	int		range;

	stack = ft_lstlast(*s_a)->content;
	size = ft_lstsize(*s_a);
	range = get_init_range(*s_a);
	if (size - stack->fi <= range && stack->fi > 2)
		record_instr(instrs[9], s_a, s_b, instr_lst);
	else
		init_rotator(s_a, s_b, instr_lst, instrs);
}

//#include <stdio.h>
//#include "stack_printer.c"

void	initial_sort(t_list **s_a, t_list **s_b,
	t_list **instr_lst, char **instrs)
{
	while (ft_lstsize(*s_a) > 3)
	{
		initial_instr(s_a, s_b, instr_lst, instrs);
	}
}
//		/*DEBUG*/print_stacks(*s_a, *s_b);
//		/*DEBUG*/ft_printf_fd(2, "PICKED INSTRUCTION %s\n", instrs[instr_i]);
//		/*DEBUG*/ft_printf_fd(2, "<<BREAK POINT>>"); getchar();
