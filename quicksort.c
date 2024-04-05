/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:10:03 by njackson          #+#    #+#             */
/*   Updated: 2024/04/05 10:39:50 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_solver.h"

int	partition(t_imap *arr, int start, int end)
{
	int	mid;
	int	i;

	mid = start;
	while (arr[mid].v < arr[end].v && mid < end)
	{
		mid++;
	}
	i = mid + 1;
	while (i < end)
	{
		if (arr[i].v < arr[end].v)
		{
			ft_memswap(&(arr[i]), &(arr[mid++]), sizeof(t_imap));
		}
		i++;
	}
	ft_memswap(&(arr[end]), &(arr[mid]), sizeof(t_imap));
	return (mid);
}

t_imap	*quicksort(t_imap *arr, int start, int end)
{
	int	mid;

	if (start >= end)
		return (arr);
	mid = partition(arr, start, end);
	quicksort(arr, start, mid - 1);
	quicksort(arr, mid + 1, end);
	return (arr);
}
