/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:36:57 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/13 17:38:51 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
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
		    if (arr[j] > arr[j+1])
            	swap(&arr[j], &arr[j+1]);
	   }
	   j++;
   }
   j++;
}

int		sorted(t_all *lst)
{
	while (lst && lst->next)
	{
		if ((*(int *)lst->content) > (*(int *)lst->next->content))
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	fill_sort(t_all *ps)
{
	t_list	*tmplst;
	int		*tmpnbr;
	int		i;

	i = 0;
	while(i < ps->arr_size)
	{
		tmpnbr = (int *)malloc(sizeof(t_list) * 1);
		if (tmpnbr)
		{
			*tmpnbr = ps->arr[i];
			tmplst = ft_lstnew(tmpnbr);
		}
		if (!tmpnbr || !tmplst)
		{
			free(tmplst);
			free(tmpnbr);
			// ft_lst_clear();
			error("error list filing");
		}
		ft_lstadd_back(ps->stack_a, tmpnbr);
		i++;
	}
	ps->arr_len_a = ps->arr_size;
}

void	actions(t_all *ps)
{
	fill_sort(ps);
	if (sotred(ps->stack_a) == -1)
	{
		// ft_lst_clear();
		return (-1);
	}
	bubbleSort(ps->arr, ps->arr_size);
}