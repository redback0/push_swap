/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 09:42:30 by njackson          #+#    #+#             */
/*   Updated: 2024/04/05 11:00:05 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solver.h"

int	main(void) // needs to take an array
{
	int		arr[10] = {900, 600, 700, 800, 100, 400, 500, 300, 200, 0};
	int		arr_size = 10;
	int		i;

	index_arr(arr, arr_size);
	i = 0;
	while (i < arr_size)
		ft_printf_fd(1, "%d\n", arr[i++]);
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
