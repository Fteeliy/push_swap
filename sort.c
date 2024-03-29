/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:07:42 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/17 18:57:58 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_b(t_all *ps)
{
	while (ps->len_a > 3)
	{
		if (*(int *)ps->stack_a->content != ps->arr[0]
			&& *(int *)ps->stack_a->content != ps->arr[ps->arr_size - 1]
			&& *(int *)ps->stack_a->content != ps->arr[ps->arr_size / 2])
		{
			pb(ps, 1);
			if (*(int *)ps->stack_b->content < ps->arr[ps->arr_size / 2])
				rb(ps, 1);
		}
		else
			ra(ps, 1);
	}
}

static int	search_in_stack_a(t_all *ps, int value_in_b)
{
	t_list	*next;
	t_list	*prev;
	int		pos_a;

	pos_a = 0;
	next = ps->stack_a;
	prev = ft_lstlast(ps->stack_a);
	while (next != NULL)
	{
		if (*(int *)prev->content < value_in_b \
		&& *(int *)next->content > value_in_b)
			return (pos_a);
		next = next->next;
		if (prev->next)
			prev = prev->next;
		else
			prev = ps->stack_a;
		pos_a++;
	}
	return (pos_a);
}

static int	scoring(t_all *ps, t_list *el, int i)
{
	int	up_a;
	int	up_b;

	up_b = i;
	up_a = search_in_stack_a(ps, *(int *)el->content);
	el->score_a = -up_a;
	el->score_b = -up_b;
	if (c_ops(el->score_a, el->score_b)
		> c_ops((ps->len_a - up_a), (ps->len_b - up_b)))
	{
		el->score_a = (ps->len_a - up_a);
		el->score_b = (ps->len_b - up_b);
	}
	if (c_ops(el->score_a, el->score_b) > c_ops(-up_a, (ps->len_b - up_b)))
	{
		el->score_a = -up_a;
		el->score_b = (ps->len_b - up_b);
	}
	if (c_ops(el->score_a, el->score_b) > c_ops((ps->len_a - up_a), -up_b))
	{
		el->score_a = (ps->len_a - up_a);
		el->score_b = -up_b;
	}
	return (c_ops(el->score_a, el->score_b));
}

t_list	*current_node(t_all *ps)
{
	t_list	*tmp;
	t_list	*current;
	int		min;
	int		min_ops;
	int		i;

	tmp = ps->stack_b;
	current = ps->stack_b;
	i = 0;
	min = scoring(ps, tmp, i);
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
		min_ops = scoring(ps, tmp, i);
		if (c_ops(current->score_a, current->score_b) > min_ops)
		{
			current = tmp;
			min = min_ops;
		}
	}
	return (current);
}

void	sort(t_all *ps)
{
	t_list	*tmp;

	fill_b(ps);
	presort3(ps);
	while (ps->len_b > 0)
	{
		tmp = current_node(ps);
		executor(ps, tmp);
	}
	stack_a_sort(ps);
}
