/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:47:32 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/17 18:36:04 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	presort3(t_all *ps)
{
	int	e1;
	int	e2;
	int	e3;

	e1 = *(int *)(ps->stack_a->content);
	e2 = *(int *)(ps->stack_a->next->content);
	e3 = *(int *)(ps->stack_a->next->next->content);
	if (e2 < e1 && e2 < e3 && e1 < e3)
		sa(ps, 1);
	else if (e2 < e1 && e3 < e2 && e3 < e1)
		sa(ps, 1);
	else if (e1 < e2 && e3 < e2 && e1 < e3)
		sa(ps, 1);
}

void	sort3(t_all *ps)
{
	int	e1;
	int	e2;
	int	e3;

	presort3(ps);
	e1 = *(int *)(ps->stack_a->content);
	e2 = *(int *)(ps->stack_a->next->content);
	e3 = *(int *)(ps->stack_a->next->next->content);
	if (e2 < e1 && e2 < e3 && e3 < e1)
		ra(ps, 1);
	else if (e1 < e2 && e3 < e2 && e3 < e1)
		rra(ps, 1);
}

static	int	search_min(t_list *lst)
{
	int	steps;
	int	count;
	int	min;

	steps = 0;
	count = 0;
	min = *(int *)lst->content;
	while (lst->next != NULL)
	{
		lst = lst->next;
		steps++;
		if (*(int *)lst->content < min)
		{
			min = *(int *)lst->content;
			count = steps;
		}
	}
	return (count);
}

void	sort5(t_all *ps)
{
	int	rot_score;

	while (ps->len_a > 3)
	{
		rot_score = search_min(ps->stack_a);
		if (rot_score < ps->len_a - rot_score)
		{
			while (rot_score--)
				ra(ps, 1);
		}
		else
		{
			while (ps->len_a - rot_score++ > 0)
				rra(ps, 1);
		}
		pb(ps, 1);
	}
	sort3(ps);
	while (ps->len_b)
		pa(ps, 1);
}
