/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:10:03 by njackson          #+#    #+#             */
/*   Updated: 2024/04/04 10:34:59 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(int *arr, int start, int end)
{
	int	mid;
	int	i;

	mid = start;
	while (arr[mid] < arr[end] && mid < end)
	{
		mid++;
	}
	i = mid + 1;
	while (i < end)
	{
		if (arr[i] < arr[end])
		{
			ft_swap(arr + i, arr + mid++);
		}
		i++;
	}
	ft_swap(arr + end, arr + mid);
	return (mid);
}

int	*quicksort(int *arr, int start, int end)
{
	int	mid;

	if (start >= end)
		return (arr);
	mid = partition(arr, start, end);
	quicksort(arr, start, mid - 1);
	quicksort(arr, mid + 1, end);
	return (arr);
}
