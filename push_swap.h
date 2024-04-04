/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:26:16 by njackson          #+#    #+#             */
/*   Updated: 2024/04/04 12:20:03 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

// push_swap instructions
t_list	*rotate_stack(t_list **stack);
t_list	*rev_rotat_stack(t_list **stack);
t_list	*push_stack(t_list **to, t_list **from);
t_list	*swap_stack(t_list **stack);
t_list	*do_instr(char *instr, t_list **s_a, t_list **s_b);

t_list	*swap_ab(t_list **s_a, t_list **s_b);
t_list	*rotate_ab(t_list **s_a, t_list **s_b);
t_list	*rev_rotate_ab(t_list **s_a, t_list **s_b);

// quicksort functions
int	partition(int *arr, int start, int end);
int	*quicksort(int *arr, int start, int end);

#endif
