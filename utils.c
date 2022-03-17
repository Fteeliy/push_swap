/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:55:14 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/17 13:40:34 by wdwain           ###   ########.fr       */
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

void	lst_clear(t_all *ps)
{
	free(ps->arr);
	ps->arr = NULL;
	ft_lstclear(&ps->stack_a, free);
	ft_lstclear(&ps->stack_b, free);
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
			j++;
	   }
	   i++;
   }
}

void	print_arr(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr_fd(arr[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

void	print_lst(t_list *lst)
{
	while (lst)
	{
		ft_putnbr_fd(*(int *)lst->content, 1);
		ft_putchar_fd('\n', 1);
		lst = lst->next;
	}
}