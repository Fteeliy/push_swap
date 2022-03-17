/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:13:40 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/17 12:57:16 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs_(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	max_abs(int a, int b)
{
	if (abs_(a) > abs_(b))
		return (abs_(a));
	return (abs_(b));
}

int	count_ops(int a, int b)
{
	if (a * b > 0)
		return (max_abs(a, b));
	else
		return (abs_(a) + abs_(b));
}

void	executor(t_all *ps, t_list *el)
{
	while (el->score_a > 0 && el->score_b > 0 && el->score_a--
		&& el->score_b--)
		rrr(ps);
	while (el->score_a < 0 && el->score_b < 0 && el->score_a++
		&& el->score_b++)
		rr(ps);
	while (el->score_a > 0 && el->score_a--)
		rra(ps);
	while (el->score_a < 0 && el->score_a++)
		ra(ps);
	while (el->score_b > 0 && el->score_b--)
		rrb(ps);
	while (el->score_b < 0 && el->score_b++)
		rb(ps);
	pa(ps);
}

void	stack_a_sort(t_all *ps)
{
	t_list	*lst;
	int		len_a;
	int		min;
	int		i;

	lst = ps->stack_a;
	len_a = ps->len_a;
	min = ps->arr[0];
	i = 0;
	while (lst && *(int *)lst->content != min)
	{
		i++;
		lst = lst->next;
	}
	if (i < (len_a - i))
		while (i--)
			ra(ps);
	else
	{
		i = len_a - i;
		while (i--)
			rra(ps);
	}
}