/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42adel.o>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:26:15 by njackson          #+#    #+#             */
/*   Updated: 2024/04/26 13:26:17 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	int		*arr;
	t_list	*stack_a;
	int		err;
	int		i;

	arr = 0;
	if (argc < 2)
		return (0);
	arr = (int *)malloc((argc - 1) * sizeof(int));
	err = 0;
	i = -1;
	while (++i < argc - 1 && !err)
		arr[i] = ft_atoi_strict(argv[i + 1], &err);
	if (err || check_dups(arr, argc - 1))
		checker_err(arr);
	stack_a = init_stack_a(arr, argc - 1);
	if (check_instrs(stack_a))
		ft_printf_fd(1, "OK\n");
	else
		ft_printf_fd(1, "KO\n");
	free(arr);
}

void	checker_err(int *arr)
{
	if (arr)
		free(arr);
	ft_printf_fd(1, "Error\n");
	exit(1);
}

int	check_dups(int *arr, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = i;
		while (j-- > 0)
		{
			if (arr[i] == arr[j])
				return (1);
		}
		i++;
	}
	return (0);
}

t_list	*init_stack_a(int *arr, int size)
{
	t_list	*stack;
	t_list	*end;
	int		*cont;

	stack = 0;
	while (size--)
	{
		cont = (int *)malloc(sizeof(int));
		*cont = arr[size];
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

int	check_instrs(t_list *s_a)
{
	t_list	*s_b;
	char	*instr;
	int		out;

	s_b = 0;
	instr = get_next_line(0);
	while (instr)
	{
		process_instr(instr, &s_a, &s_b);
		instr = get_next_line(0);
	}
	if (s_b)
		ft_lstclear(&s_b, *free);
	out = 0;
	if (stack_in_order(s_a) && !s_b)
		out = 1;
	if (s_a)
		ft_lstclear(&s_a, *free);
	return (out);
}
