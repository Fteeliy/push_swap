/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:55:14 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/16 15:17:04 by wdwain           ###   ########.fr       */
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