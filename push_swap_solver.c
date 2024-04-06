/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 09:42:30 by njackson          #+#    #+#             */
/*   Updated: 2024/04/06 17:05:30 by njackson         ###   ########.fr       */
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

	arr = (int *)malloc((argc - 1) * sizeof(int));
	err = 0;
	i = -1;
	while (++i < argc - 1 && !err)
		arr[i] = ft_atoi_strict(argv[i + 1], &err);
	if (err || check_dups(arr, argc - 1))
	{
		free(arr);
		ft_printf_fd(1, "Error\n");
		return (1);
	}
	arr = index_arr(arr, argc - 1);
	stack_a = init_stack_a(arr, argc - 1);
	instr = distance_sort(stack_a);
	// optional: run an efficiency function on the instructions
	output_instr(instr);
	return (0);
}

int	*index_arr(int *arr, int size)
{
	t_imap	*imap;
	int		i;

	imap = (t_imap *)malloc(size * sizeof(*imap));
	i = 0;
	while (i < size)
	{
		imap[i].v = arr[i];
		imap[i].oi = i;
		i++;
	}
	imap = quicksort(imap, 0, size - 1);
	i = 0;
	while (i < size)
	{
		arr[imap[i].oi] = i;
		i++;
	}
	free (imap);
	return (arr);
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


