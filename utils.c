/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:55:14 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/16 21:50:39 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

void ft_swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void	lst_cleaner(t_push_swap *ps)
{
	free(ps->arr);
	ft_lstclear(&ps->a, free);
	ft_lstclear(&ps->b, free);
}

void bubbleSort(int *arr, int size)
{
   int	i;
   int	j;
   
   i = 0;
   while(i < size - 1)
   {
	   j = 0;
	   while (j < size - i - 1)
	   {
		    if (arr[j] > arr[j + 1])
            	ft_swap(&arr[j], &arr[j + 1]);
	   }
	   j++;
   }
   j++;
}