/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:36:57 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/17 18:57:44 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_distributor(t_all *ps)
{
	if (ps->len_a == 2)
		sa(ps, 1);
	else if (ps->len_a == 3)
		sort3(ps);
	else if (ps->len_a < 6)
		sort5(ps);
	else
		sort(ps);
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
	while (i < ps->arr_size)
	{
		tmpnbr = (int *)malloc(sizeof(int) * 1);
		if (tmpnbr)
		{
			*tmpnbr = ps->arr[i];
			tmplst = ft_lstnew(tmpnbr);
		}
		if (!tmpnbr || !tmplst)
		{
			free(tmplst);
			free(tmpnbr);
			ft_lstclear(&ps->stack_a, free);
			error("Error\n");
		}
		ft_lstadd_back(&ps->stack_a, tmplst);
		i++;
	}
	ps->len_a = ps->arr_size;
}

int	actions(t_all *ps)
{
	fill_lst(ps);
	if (sorted(ps->stack_a))
	{
		lst_clear(ps);
		return (0);
	}
	bubble_sort(ps->arr, ps->arr_size);
	sort_distributor(ps);
	return (0);
}
