/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:02:16 by njackson          #+#    #+#             */
/*   Updated: 2024/04/26 14:02:17 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_instrs(t_list *instrs, t_list *s_a)
{
	t_list	*s_b;

	s_b = 0;
	while (instrs)
	{
		if (!do_instr(instrs->content, &s_a, &s_b))
			checker_err(0);
	}
	return (1);
}
