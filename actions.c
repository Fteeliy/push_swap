/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:36:57 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/16 15:19:06 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_distributor(t_all *ps)
{
	if (ps->stack_a == 2)
		sa(ps);
	else if (ps->stack_a == 3)
		sort3(ps);
	else if (ps->stack_a < 6)
		sort5(ps);
	else
		sort(ps);
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

int	sorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (*(int *)(lst->content) > *(int *)(lst->next->content))
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	fill_lst(t_all *ps)
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
			lst_clear(&ps->stack_a, free);
			error("error list filing");
		}
		ft_lstadd_back(ps->stack_a, tmpnbr);
		i++;
	}
	ps->arr_len_a = ps->arr_size;
}

int	actions(t_all *ps)
{
	fill_lst(ps);
	if (sotred(ps->stack_a))
	{
		lst_clear(ps);
		return (0);
	}
	bubbleSort(ps->arr, ps->arr_size);
	sort_distributor(ps);

	return (0);
}