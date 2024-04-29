/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:26:16 by njackson          #+#    #+#             */
/*   Updated: 2024/04/05 11:08:01 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

// push_swap instructions
int	rotate_stack(t_list **stack);
int	rev_rotate_stack(t_list **stack);
int	push_stack(t_list **to, t_list **from);
int	swap_stack(t_list **stack);
int	do_instr(const char *instr, t_list **s_a, t_list **s_b);

int	swap_ab(t_list **s_a, t_list **s_b);
int	rotate_ab(t_list **s_a, t_list **s_b);
int	rev_rotate_ab(t_list **s_a, t_list **s_b);

#endif
