/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:59:45 by njackson          #+#    #+#             */
/*   Updated: 2024/04/26 13:59:46 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "libft.h"
#include "push_swap.h"

int		checker_err(int *arr);
int		check_dups(int *arr, int size);
t_list	*init_stack_a(int *arr, int size);
t_list	*read_instrs(void);

int		check_instrs(t_list *instrs, t_list *s_a);

#endif
