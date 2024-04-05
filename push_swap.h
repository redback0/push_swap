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
void	rotate_stack(t_list **stack);
void	rev_rotate_stack(t_list **stack);
void	push_stack(t_list **to, t_list **from);
void	swap_stack(t_list **stack);
void	do_instr(char *instr, t_list **s_a, t_list **s_b);

void	swap_ab(t_list **s_a, t_list **s_b);
void	rotate_ab(t_list **s_a, t_list **s_b);
void	rev_rotate_ab(t_list **s_a, t_list **s_b);

#endif
