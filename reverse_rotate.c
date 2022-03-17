/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:54:55 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/17 18:37:52 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	rev_rot(t_list **node)
{
	t_list	*tmp;

	if (!(*node) || !(*node)->next)
		return ;
	tmp = *node;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = *node;
	*node = tmp->next;
	tmp->next = NULL;
}

void	rra(t_all *ps, int flag)
{
	rev_rot(&ps->stack_a);
	if (flag)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_all *ps, int flag)
{
	rev_rot(&ps->stack_b);
	if (flag)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_all *ps, int flag)
{
	rev_rot(&ps->stack_a);
	rev_rot(&ps->stack_b);
	if (flag)
		ft_putstr_fd("rrr\n", 1);
}
