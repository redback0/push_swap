/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:06:01 by njackson          #+#    #+#             */
/*   Updated: 2024/04/09 15:22:02 by njackson         ###   ########.fr       */
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

static int	get_instr(int *changes, t_list *s)
{
	if (changes[0] > 0 && changes[1] > 0)
		return (2);
	if (changes[0] > 0)
		return (0);
	if (changes[1] > 0)
		return (1);
	if (changes[3] > 0 && changes[4] > 0)
		return (5);
	if (changes[6] > 0 && changes[7] > 0)
		return (8);
	if (changes[3] > 0 && changes[3] > changes[7])
		return (3);
	if (changes[4] > 0 && changes[4] > changes[6])
		return (4);
	if (changes[6] > 0)
		return (6);
	if (changes[7] > 0)
		return (7);
	if (stack_entropy(s))
		return (9);
	return (10);
}

t_list	*distance_sort(t_list *s_a)
{
	t_list	*s_b;
	int		changes[9];
	char	**instrs;
	t_list	*instr_lst;
	int		instr_i;

	s_b = 0;
	instr_lst = 0;
	instrs = get_instr_arr();
	get_distances(&s_a, &s_b);
	while (!check_solved(s_a, s_b))
	{
		get_changes(s_a, s_b, changes);
		instr_i = get_instr(changes, s_a);
		do_instr(instrs[instr_i], &s_a, &s_b);
		if (!instr_lst)
			instr_lst = ft_lstnew(instrs[instr_i]);
		else
			ft_lstlast(instr_lst)->next = ft_lstnew(instrs[instr_i]);
		get_distances(&s_a, &s_b);
	}
	free(instrs);
	return (instr_lst);
}
