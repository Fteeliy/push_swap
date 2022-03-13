/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:06:55 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/13 21:11:58 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	push(t_list **src, t_list **dst)
{
	t_list	*tmp;

	tmp = *src;
	
	if (*src)
	{
		*src = (*src)->next;
		tmm->next = NULL;
		ft_lstadd_front(dst, tmp);
	}
}

void	pa(t_all *ps)
