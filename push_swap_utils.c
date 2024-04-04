/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:10:42 by njackson          #+#    #+#             */
/*   Updated: 2024/04/04 12:19:58 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	swap_ab(t_list **s_a, t_list **s_b)
{
	swap_stack(s_a);
	swap_stack(s_b);
	return (ft_lstnew("ss"));
}

t_list	rotate_ab(t_list **s_a, t_list **s_b)
{
	rotate_stack(s_a);
	rotate_stack(s_b);
	return (ft_lstnew("rr"));
}
