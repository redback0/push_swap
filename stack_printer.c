/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:47:42 by njackson          #+#    #+#             */
/*   Updated: 2024/04/22 16:47:44 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solver.h"

t_list	*print_sa_stack_ele(t_list *s_a, int mlt)
{
	t_stack	*c_a;
	int		tmp;

	if (s_a)
	{
		c_a = s_a->content;
		tmp = ft_log_base_n(c_a->fi, 10);
		if (tmp == 0)
			tmp = 1;
		while (tmp++ <= mlt)
			ft_printf_fd(2, " ");
		ft_printf_fd(2, "%d | ", c_a->fi);
		return (s_a->next);
	}
	else
	{
		tmp = 0;
		while (tmp++ <= mlt)
			ft_printf_fd(2, " ");
		ft_printf_fd(2, " | ");
		return (0);
	}
}

t_list	*print_sb_stack_ele(t_list *s_b, int mlt)
{
	t_stack	*c_b;
	int		tmp;

	if (s_b)
	{
		c_b = s_b->content;
		tmp = ft_log_base_n(c_b->fi, 10);
		while (tmp++ < mlt)
			ft_printf_fd(2, " ");
		ft_printf_fd(2, "%d : %d\n", c_b->fi, c_b->dist);
		return (s_b->next);
	}
	ft_printf_fd(2, "\n");
	return (0);
}

void	print_stacks(t_list *s_a, t_list *s_b) // DEBUG FUNC
{
	int		mlt;

	ft_printf_fd(2, "-- STACKS --\n");
	mlt = ft_log_base_n(ft_lstsize(s_a) + ft_lstsize(s_b), 10);
	while (s_a || s_b)
	{
		s_a = print_sa_stack_ele(s_a, mlt);
		s_b = print_sb_stack_ele(s_a, mlt);
	}
}
