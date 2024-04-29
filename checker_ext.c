/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:38:19 by njackson          #+#    #+#             */
/*   Updated: 2024/04/26 15:38:21 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	stack_in_order(t_list *s)
{
	int	a;
	int	b;

	while (s && s->next)
	{
		a = *(int *)s->content;
		b = *(int *)s->next->content;
		if (a < b)
			return (0);
		s = s->next;
	}
	return (1);
}

void	process_instr(char *instr, t_list **s_a, t_list **s_b)
{
	int	err;

	if (instr[2] == '\n')
		instr[2] = 0;
	else if (instr[3] == '\n')
		instr[3] = 0;
	else
		checker_err(0);
	err = do_instr(instr, s_a, s_b);
	if (err < 0)
		checker_err(0);
	free(instr);
}
