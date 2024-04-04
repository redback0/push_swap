/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:07:17 by njackson          #+#    #+#             */
/*   Updated: 2024/04/04 17:17:45 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_list **stack)
{
	t_list	head;
	t_list	end;

	end = *stack;
	*stack = (*stack)->next;
	head = ft_lstend(*stack);
	head->next = end;
	end->next = NULL;
}

void	rev_rotate_stack(t_list **stack)
{
	t_list	head;
	t_list	end;

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
	t_list	mv;
	t_list	tmp;

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
	t_lst	tmp;

	tmp = (*stack)->next
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	do_instr(char *instr, t_list **s_a, t_list **s_b)
{
	if (!ft_strncmp("sa", instr, 3))
		swap_stack(*s_a);
	else if (!ft_strncmp("sb", instr, 3))
		swap_stack(*s_b);

}
