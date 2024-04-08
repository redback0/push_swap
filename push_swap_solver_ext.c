/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solver_ext.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:49:55 by njackson          #+#    #+#             */
/*   Updated: 2024/04/08 20:53:48 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solver.h"

int	ps_solver_error(int *arr)
{
	if (arr)
		free(arr);
	ft_printf_fd(1, "Error\n");
	return (1);
}
