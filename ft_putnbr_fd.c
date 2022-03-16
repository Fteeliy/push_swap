/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:49:07 by wdwain          #+#    #+#             */
/*   Updated: 2022/03/16 14:58:25 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	i;
	char	c;

	i = n;
	if (i < 0)
	{
		ft_putchar_fd ('-', fd);
		i = i * (-1);
	}
	if (i < 10)
	{
		c = ('0' + i);
		ft_putchar_fd ((char)('0' + i), fd);
	}
	if (i > 9)
	{
		ft_putnbr_fd (i / 10, fd);
		ft_putchar_fd ((char)('0' + (i % 10)), fd);
	}
}