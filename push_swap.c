/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:07:17 by njackson          #+#    #+#             */
/*   Updated: 2024/04/04 10:47:34 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_instrs(int *arr)
{
}

t_list	*add_instr(t_list *lst, char *instr)
{
	lst->next = ft_lstnew(instr);
	return (lst->next);
}
