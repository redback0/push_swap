/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distances.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:56:44 by njackson          #+#    #+#             */
/*   Updated: 2024/04/05 16:54:19 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solver.h"

void	get_distances(t_list **s_a, t_list **s_b)
{
	t_list	lst;
	int		a_len;
	int		b_len;
	int		i;

	a_len = ft_lstsize(s_a);
	b_len = ft_lstsize(s_b);
	i = 0;
	lst = *s_a;
	while (i < a_len)
	{
		lst->content->dist = lst->content->fi - i;
		lst = lst->next;
	}
	i = a_len + b_len - 2;
	lst = *s_b;
	while (i > a_len - 1)
	{
		lst->content->dist = lst->content->fi - i;
		lst = lst->next;
	}
}


// TESTING ********************************************************************
t_stack	*create_stack_ele(fi)
{
	t_stack	*out;

	out = (t_stack *)malloc(sizeof(*out));
	out->fi = fi;
	out->dist = 0;
	out->new_dist = 0;
}

void	print_t_stack(t_stack s)
{
	ft_printf_fd(1, "fi:%d dist:%d new:%d\n", s.fi, s.dist, s.new);
}

int	main(void)
{
	
}
