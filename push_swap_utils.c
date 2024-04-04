/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:10:42 by njackson          #+#    #+#             */
/*   Updated: 2024/04/04 13:41:14 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_list **s_a, t_list **s_b)
{
	swap_stack(s_a);
	swap_stack(s_b);
}

void	rotate_ab(t_list **s_a, t_list **s_b)
{
	rotate_stack(s_a);
	rotate_stack(s_b);
}
