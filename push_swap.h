/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:26:16 by njackson          #+#    #+#             */
/*   Updated: 2024/04/04 11:06:37 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

t_list	*get_instrs(int *arr);
t_list	*run_instr(t_list *lst, char *instr);

// quicksort functions
int	partition(int *arr, int start, int end);
int	*quicksort(int *arr, int start, int end);

#endif
