/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:07:17 by njackson          #+#    #+#             */
/*   Updated: 2024/04/04 12:20:05 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*rotate_stack(t_list **stack)
{
}

t_list	*rev_rotate_stack(t_list **stack)

t_list	*push_stack(t_list **to, t_list **from)
{
}

t_list	*swap_stack(t_list **stack)
{
}

t_list	*do_instr(char *instr, t_list **s_a, t_list **s_b)
{
	if (!ft_strncmp("sa", instr, 3))
		swap_stack(*s_a);
	else if (!ft_strncmp("sb", instr, 3))
		swap_stack(*s_b);

}
