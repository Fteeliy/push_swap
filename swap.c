/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:26:14 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/17 18:36:14 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	swap(t_list **node)
{
	t_list	*tmp;

	if (ft_lstsize(*node) < 2)
		return ;
	tmp = *node;
	*node = (*node)->next;
	tmp->next = (*node)->next;
	(*node)->next = tmp;
}

void	sa(t_all *ps, int flag)
{
	swap(&ps->stack_a);
	if (flag)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_all *ps, int flag)
{
	swap(&ps->stack_b);
	if (flag)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_all *ps, int flag)
{
	swap(&ps->stack_a);
	swap(&ps->stack_b);
	if (flag)
		ft_putstr_fd("ss\n", 1);
}
