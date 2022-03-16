/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:06:55 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/16 15:16:30 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	push(t_list **src, t_list **dst)
{
	t_list	*tmp;

	tmp = *src;
	
	if (src)
	{
		*src = (*src)->next;
		tmp->next = NULL;
		ft_lstadd_front(dst, tmp);
	}
}

void	pa(t_all *ps)
{
	if (ps->stack_b)
	{
		push(&ps->stack_b, &ps->stack_a);
		ps->len_a++;
		ps->len_b--;
	}
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_all *ps)
{
	if (ps->stack_a)
	{
		push(&ps->stack_a, &ps->stack_b);
		ps->len_a--;
		ps->len_b++;
	}
	ft_putstr_fd("pb\n", 1);
}
