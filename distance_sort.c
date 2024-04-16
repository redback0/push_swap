/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:06:01 by njackson          #+#    #+#             */
/*   Updated: 2024/04/15 22:39:38 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solver.h"


#include <libc.h>

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

static int	get_instr(int *changes, t_list *s, int last)
{
	int	out;

	if (last == 3 || last == 4)
		changes[last + 3] = -1;
	else if (last == 6 || last == 7)
		changes[last - 3] = -1;
	else if (last == 5)
	{
		changes[6] = -1;
		changes[7] = -1;
		changes[8] = -1;
	}
	else if (last == 8)
	{
		changes[3] = -1;
		changes[4] = -1;
		changes[5] = -1;
	}
	out = ft_arrmax(changes, 9);
	if (changes[out] > 0)
		return (out);
	if (!stack_in_order(s))
		return (9);
	return (10);
}


void	print_stacks(t_list *s_a, t_list *s_b) // DEBUG FUNC
{
	t_stack	*c_a;
	t_stack	*c_b;
	int		mlt;
	int		tmp;

	ft_printf_fd(2, "-- STACKS --\n");
	mlt = ft_log_base_n(ft_lstsize(s_a) + ft_lstsize(s_b), 10);
	while (s_a || s_b)
	{
		if (s_a)
		{
			c_a = s_a->content;
			tmp = ft_log_base_n(c_a->fi, 10);
			if (tmp == 0)
				tmp = 1;
			while (tmp++ <= mlt)
				ft_printf_fd(2, " ");
			ft_printf_fd(2, "%d | ", c_a->fi);
			s_a = s_a->next;
		}
		else
		{
			tmp = 0;
			while (tmp++ <= mlt)
				ft_printf_fd(2, " ");
			ft_printf_fd(2, " | ");
		}
		if (s_b)
		{
			c_b = s_b->content;
			tmp = ft_log_base_n(c_b->fi, 10);
			while (tmp++ < mlt)
				ft_printf_fd(2, " ");
			ft_printf_fd(2, "%d : %d\n", c_b->fi, c_b->dist);
			s_b = s_b->next;
		}
		else
			ft_printf_fd(2, "\n");
	}
}


static void	initial_sort(t_list **s_a, t_list **s_b, t_list **instr_lst, char **instrs)
{
	int	changes[9];
	int	instr_i;

//	int		s_a_sorted = 0;

	instr_i = -1;
	get_distances(s_a, s_b);
	while (stack_entropy(*s_a))
	{
		get_changes(*s_a, *s_b, changes);
		instr_i = get_instr(changes, *s_a, instr_i);
//		/*DEBUG*/if (s_a_sorted) {getchar(); print_stacks(*s_a, *s_b); ft_printf_fd(2, "PICKED INSTR: %s\n", instrs[instr_i]);}
//		/*DEBUG*/if (!s_a_sorted && !stack_entropy(*s_a))
//		{
//			print_stacks(*s_a, *s_b);
//			ft_printf_fd(2, "STACK A SORTED AT %d INSTRUCTIONS\nSTACK B ENTROPY: %d\n", ft_lstsize(instr_lst), stack_entropy(*s_b));
//			s_a_sorted = 1;
//		} /*DEBUG*/
		do_instr(instrs[instr_i], s_a, s_b);
		if (!*instr_lst)
			*instr_lst = ft_lstnew(instrs[instr_i]);
		else
			ft_lstlast(*instr_lst)->next = ft_lstnew(instrs[instr_i]);
		get_distances(s_a, s_b);
	}
}

static void	return_sort(t_list **s_a, t_list **s_b, t_list **instr_lst, char **instrs)
{
	int	changes[9];
	int	instr_i;


	instr_i = -1;
	get_distances(s_a, s_b);
	while (!check_solved(*s_a, *s_b))
	{
		get_changes(*s_a, *s_b, changes);
		instr_i = get_instr(changes, *s_a, instr_i);
//		/*DEBUG*/print_stacks(*s_a, *s_b); 
//		/*DEBUG*/ft_printf_fd(2, "PICKED INSTR: %s\n", instrs[instr_i]);
//		/*DEBUG*/if (!stack_entropy(*s_a)) ft_printf_fd(2, "STACK A SORTED AT %d INSTRUCTIONS\nSTACK B ENTROPY: %d\n", ft_lstsize(*instr_lst), stack_entropy(*s_b));
		do_instr(instrs[instr_i], s_a, s_b);
		if (!*instr_lst)
			*instr_lst = ft_lstnew(instrs[instr_i]);
		else
			ft_lstlast(*instr_lst)->next = ft_lstnew(instrs[instr_i]);
		get_distances(s_a, s_b);
//		/*DEBUG*/getchar();
	}
}

t_list	*distance_sort(t_list *s_a)
{
	t_list	*s_b;
	char	**instrs;
	t_list	*instr_lst;

	s_b = 0;
	instr_lst = 0;
	instrs = get_instr_arr();
	initial_sort(&s_a, &s_b, &instr_lst, instrs);
	return_sort(&s_a, &s_b, &instr_lst, instrs);
	free(instrs);
	return (instr_lst);
}

int	stack_in_order(t_list *s)
{
	t_stack	*a;
	t_stack	*b;

	while (s && s->next)
	{
		a = s->content;
		b = s->next->content;
		if (a->fi > b->fi)
			return (0);
		s = s->next;
	}
	return (1);
}
