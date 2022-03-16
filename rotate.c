/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:47:47 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/16 15:22:53 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	rot(t_list **node)
{
	t_list	*tmp;

	if (!(*node) || !(*node)->next)
		return ;
	tmp = *node;
	*node = (*node)->next;
	ft_lstadd_back(node, tmp);
	tmp->next = NULL;
}

void	ra(t_all *ps)
{
	rot(&ps->stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_all *ps)
{
	rot(&ps->stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_all *ps)
{
	rot(&ps->stack_a);
	rot(&ps->stack_b);
	ft_putstr_fd("rr\n", 1);
}