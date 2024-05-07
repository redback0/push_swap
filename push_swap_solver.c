/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 09:42:30 by njackson          #+#    #+#             */
/*   Updated: 2024/05/07 15:42:25 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solver.h"

int	main(int argc, char *argv[])
{
	int		*arr;
	t_list	*stack_a;
	t_list	*instr;
	int		err;
	int		i;

	arr = 0;
	if (argc < 2)
		return (ps_solver_error(arr));
	arr = (int *)malloc((argc - 1) * sizeof(int));
	err = 0;
	i = -1;
	while (++i < argc - 1 && !err)
		arr[i] = ft_atoi_strict(argv[i + 1], &err);
	if (err || check_dups(arr, argc - 1))
		return (ps_solver_error(arr));
	arr = index_arr(arr, argc - 1);
	stack_a = init_stack_a(arr, argc - 1);
	free(arr);
	instr = distance_sort(stack_a);
	if (ft_lstsize(instr) > 2)
		cutdown_instr(&instr);
	output_instr(instr);
	return (0);
}

int	*index_arr(int *arr, int size)
{
	t_imap	*imap;
	int		i;

	imap = (t_imap *)malloc(size * sizeof(*imap));
	i = size;
	while (i--)
	{
		imap[i].v = arr[i];
		imap[i].oi = i;
	}
	imap = quicksort(imap, 0, size - 1);
	i = 0;
	while (size--)
	{
		arr[imap[i].oi] = size;
		i++;
	}
	free (imap);
	return (arr);
}

t_list	*init_stack_a(int *arr, int size)
{
	t_list	*stack;
	t_list	*end;
	t_stack	*cont;

	stack = 0;
	while (size--)
	{
		cont = (t_stack *)malloc(sizeof(*cont));
		cont->fi = arr[size];
		cont->dist = 0;
		if (!stack)
		{
			stack = ft_lstnew(cont);
			end = stack;
		}
		else
		{
			end->next = ft_lstnew(cont);
			end = end->next;
		}
	}
	return (stack);
}

static void	del(void *ptr)
{
	(void)ptr;
}

void	output_instr(t_list *instr)
{
	char	**instrs;
	t_list	*lst;

	lst = instr;
	while (instr)
	{
		ft_printf_fd(1, "%s\n", instr->content);
		instr = instr->next;
	}
	instrs = get_instr_arr();
	ft_split_free(instrs, *free);
	ft_lstclear(&lst, *del);
}
