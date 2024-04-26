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
