/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njackson <njackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:10:03 by njackson          #+#    #+#             */
/*   Updated: 2024/04/04 12:16:37 by njackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(int *arr, int start, int end)
{

}

// NEEDS CHANGING
t_list	*quicksort(int *arr, t_list *s_a, t_list *s_b)
{
	int	mid;

	if (start >= end)
		return (arr);
	mid = partition(arr, start, end);
	quicksort(arr, start, mid - 1);
	quicksort(arr, mid + 1, end);
	return (arr);
}
