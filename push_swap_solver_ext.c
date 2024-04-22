/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solver_ext.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:49:55 by njackson          #+#    #+#             */
/*   Updated: 2024/04/22 18:54:34 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solver.h"

void	ft_lstdeltwo(t_list *lst, void (*del)(void *))
{
	ft_lstdelone(lst->next, del);
	ft_lstdelone(lst, del);
}

t_list	*comb_instr(char *curr, char *next)
{
	if ((!ft_strncmp(curr, "sa", 3)  && !ft_strncmp(next, "sb", 3))
		|| (!ft_strncmp(curr, "sb", 3) && !ft_strncmp(next, "sa", 3)))
		return (ft_lstnew(ft_strdup("ss")));
	if ((!ft_strncmp(curr, "ra", 3) && !ft_strncmp(next, "rb", 3))
		|| (!ft_strncmp(curr, "rb", 3) && !ft_strncmp(next, "ra", 3)))
		return (ft_lstnew(ft_strdup("rr")));
	if ((!ft_strncmp(curr, "rra", 4) && !ft_strncmp(next, "rrb", 4))
		|| (!ft_strncmp(curr, "rrb", 4) && !ft_strncmp(next, "rra", 4)))
		return (ft_lstnew(ft_strdup("rrr")));
	return (0);
}

void	cutdown_instr(t_list **i_lst)
{
	t_list	*lst;
	t_list	*new;

	if (ft_lstsize(*i_lst) < 3)
		return ;
	/*DEBUG*/ft_printf_fd(2, "%s, %s\n", (*i_lst)->content, (*i_lst)->next->content);
	new = comb_instr((*i_lst)->content, (*i_lst)->next->content);
	if (new)
	{
		new->next = (*i_lst)->next->next;
		ft_lstdeltwo(*i_lst, *free);
		*i_lst = new;
	}
	lst = (*i_lst);
	while (lst->next->next)
	{
		/*DEBUG*/ft_printf_fd(2, "%s, %s\n", lst->next->content, lst->next->next->content);
		new = comb_instr(lst->next->content, lst->next->next->content);
		if (new)
		{
			new->next = lst->next->next->next;
			ft_lstdeltwo(lst->next, *free);
			lst->next = new;
			/*DEBUG*/ft_printf_fd(2, "REPLACED WITH %s\n", new->content);
		}
		lst = lst->next;
	}
}

int	ps_solver_error(int *arr)
{
	if (arr)
		free(arr);
	ft_printf_fd(1, "Error\n");
	return (1);
}
