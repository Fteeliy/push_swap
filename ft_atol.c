/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:08:36 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/13 11:33:44 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	return (c == '\f' || c == '\r' || c == ' ');
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_issign(int *sign, char sn)
{
	*sign = 1;
	if (sn == '-' || sn == '+')
	{
		if (sn == '-')
			*sign = -1;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str, int *nbr)
{
	size_t	res;
	int		sign;

	res = 0;
	while (ft_isspace(*str))
		str++;
	str += ft_issign(&sign, *str);
	while (*str && ft_isdigit(*str))
	{
		res = res * 10 + *str - '0';
		str++;
		if ((res > INT_MAX && sign == 1)
			|| (res > (unsigned long long)INT_MAX + 1 && sign == -1))
			return (-1);
	}
	if (*str)
		return (-1);
	*nbr = (sign * res);
	return (0);
}