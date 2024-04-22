/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:07:17 by njackson          #+#    #+#             */
/*   Updated: 2024/04/09 12:49:05 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_instr(const char *instr, t_list **s_a, t_list **s_b)
{
	if (!ft_strncmp("sa", instr, 3))
		swap_stack(s_a);
	else if (!ft_strncmp("sb", instr, 3))
		swap_stack(s_b);
	else if (!ft_strncmp("ss", instr, 3))
		swap_ab(s_a, s_b);
	else if (!ft_strncmp("pa", instr, 3))
		push_stack(s_a, s_b);
	else if (!ft_strncmp("pb", instr, 3))
		push_stack(s_b, s_a);
	else if (!ft_strncmp("ra", instr, 3))
		rotate_stack(s_a);
	else if (!ft_strncmp("rb", instr, 3))
		rotate_stack(s_b);
	else if (!ft_strncmp("rr", instr, 3))
		rotate_ab(s_a, s_b);
	else if (!ft_strncmp("rra", instr, 4))
		rev_rotate_stack(s_a);
	else if (!ft_strncmp("rrb", instr, 4))
		rev_rotate_stack(s_b);
	else if (!ft_strncmp("rrr", instr, 4))
		rev_rotate_ab(s_a, s_b);
}

void	rev_rotate_stack(t_list **stack)
{
	t_list	*head;
	t_list	*end;

	if (ft_lstsize(*stack) < 2)
		return ;
	end = *stack;
	*stack = (*stack)->next;
	head = ft_lstlast(*stack);
	head->next = end;
	end->next = NULL;
}

void	rotate_stack(t_list **stack)
{
	t_list	*head;
	t_list	*end;

	if (ft_lstsize(*stack) < 2)
		return ;
	end = *stack;
	while (end->next->next)
		end = end->next;
	head = end->next;
	head->next = *stack;
	end->next = NULL;
	*stack = head;
}

void	push_stack(t_list **to, t_list **from)
{
	t_list	*mv;
	t_list	*tmp;

	if ((*from)->next)
	{
		tmp = *from;
		while (tmp->next->next)
			tmp = tmp->next;
		mv = tmp->next;
		tmp->next = NULL;
	}
	else
	{
		mv = *from;
		*from = NULL;
	}
	if (*to)
		ft_lstlast(*to)->next = mv;
	else
		*to = mv;
}

void	swap_stack(t_list **stack)
{
	t_list	*third;
	t_list	*second;
	t_list	*last;

	if (ft_lstsize(*stack) < 3)
	{
		second = *stack;
		last = second->next;
		*stack = last;
		last->next = second;
		second->next = 0;
	}
	else
	{
		third = *stack;
		while (third->next->next->next)
			third = third->next;
		second = third->next;
		last = second->next;
		third->next = last;
		last->next = second;
		second->next = 0;
	}
}
