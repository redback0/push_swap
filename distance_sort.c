/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:06:01 by njackson          #+#    #+#             */
/*   Updated: 2024/04/19 13:50:15 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solver.h"

static char	**get_instr_arr(void)
{
	char	**out;

	out = (char **)malloc(11 * sizeof(char *));
	out[0] = ft_strdup("sa");
	out[1] = ft_strdup("sb");
	out[2] = ft_strdup("ss");
	out[3] = ft_strdup("ra");
	out[4] = ft_strdup("rb");
	out[5] = ft_strdup("rr");
	out[6] = ft_strdup("rra");
	out[7] = ft_strdup("rrb");
	out[8] = ft_strdup("rrr");
	out[9] = ft_strdup("pb");
	out[10] = ft_strdup("pa");
	return (out);
}

void	record_instr(char *instr, t_list **s_a,
	t_list **s_b, t_list **instr_lst)
{
	do_instr(instr, s_a, s_b);
	if (!*instr_lst)
		*instr_lst = ft_lstnew(instr);
	else
		ft_lstlast(*instr_lst)->next = ft_lstnew(instr);
	get_distances(s_a, s_b);
}

//#include "stack_printer.c"
//#include <stdio.h> /*DEBUG*/

void	sort_three(t_list **s_a, t_list **s_b,
	t_list **instr_lst, char **instrs)
{
	t_stack	*stacks[3];

	if (!(*s_a)->next)
		return ;
	stacks[0] = (*s_a)->content;
	stacks[1] = (*s_a)->next->content;
	if ((*s_a)->next->next)
	{
		stacks[2] = (*s_a)->next->next->content;
		if (stacks[0]->fi > stacks[1]->fi && stacks[1]->fi < stacks[2]->fi)
			record_instr(instrs[6], s_a, s_b, instr_lst);
		else if (stacks[0]->fi > stacks[2]->fi)
			record_instr(instrs[3], s_a, s_b, instr_lst);
		stacks[0] = (*s_a)->content;
		stacks[1] = (*s_a)->next->content;
		stacks[2] = (*s_a)->next->next->content;
		if (stacks[1]->fi > stacks[2]->fi)
			record_instr(instrs[0], s_a, s_b, instr_lst);
	}
}
//	/*DEBUG*/print_stacks(*s_a, *s_b);
//	/*DEBUG*/ft_printf_fd(2, "<<BREAK POINT>>"); getchar();

t_list	*distance_sort(t_list *s_a)
{
	t_list	*s_b;
	char	**instrs;
	t_list	*instr_lst;

	s_b = 0;
	instr_lst = 0;
	instrs = get_instr_arr();
	initial_sort(&s_a, &s_b, &instr_lst, instrs);
	sort_three(&s_a, &s_b, &instr_lst, instrs);
	return_sort(&s_a, &s_b, &instr_lst, instrs);
	free(instrs);
	return (instr_lst);
}
//	/*DEBUG*/ft_printf_fd(2, "SWAPPED AT: %d\n", ft_lstsize(instr_lst));
//	/*DEBUG*/ft_printf_fd(2, "<<BREAK POINT>>"); getchar();
