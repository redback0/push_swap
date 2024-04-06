/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distances.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:56:44 by njackson          #+#    #+#             */
/*   Updated: 2024/04/06 13:20:35 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solver.h"

void	get_distances(t_list **s_a, t_list **s_b)
{
	t_list	*lst;
	t_stack	*cont;
	int		a_len;
	int		b_len;
	int		i;

	a_len = ft_lstsize(*s_a);
	b_len = ft_lstsize(*s_b);
	i = 0;
	lst = *s_a;
	while (i < a_len)
	{
		cont = (t_stack *)lst->content;
		cont->dist = cont->fi - i++;
		lst = lst->next;
	}
	i = a_len + b_len - 1;
	lst = *s_b;
	while (i >= a_len)
	{
		cont = (t_stack *)lst->content;
		cont->dist = cont->fi - i--;
		lst = lst->next;
	}
}


// TESTING ********************************************************************
t_stack	*create_stack_ele(int fi)
{
	t_stack	*out;

	out = (t_stack *)malloc(sizeof(*out));
	out->fi = fi;
	out->dist = 0;
	return (out);
}

void	print_t_stack(t_stack s)
{
	ft_printf_fd(1, "fi:%d dist:%d new:%d\n", s.fi, s.dist);
}

int	main(void)
{
	t_list	*s_a;
	t_list	*s_b;

	ft_printf_fd(1, "CREATING LIST OF STACKS\n");
	s_a = ft_lstnew(create_stack_ele(2));
	s_a->next = ft_lstnew(create_stack_ele(0));
	s_b = ft_lstnew(create_stack_ele(1));
	ft_printf_fd(1, "GETTING DISTANCES\n");
	get_distances(&s_a, &s_b);
	ft_printf_fd(1, "PRINTING STACKS\n");
	print_t_stack(*(t_stack *)s_a->content);
	print_t_stack(*(t_stack *)s_a->next->content);
	print_t_stack(*(t_stack *)s_b->content);
}
