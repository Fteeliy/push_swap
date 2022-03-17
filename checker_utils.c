/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:07:14 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/17 18:15:31 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "gnl.h"

int	ft_same_digits_c(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parce_argv_c(int *arr, char **argv)
{
	int		i;
	char	**splited;
	int		flag;
	int		count_argv;

	count_argv = 0;
	flag = 0;
	while (flag != -1 && *argv)
	{
		splited = ft_split(*argv++, ' ');
		if (!splited)
			error("Error\n");
		i = 0;
		while (splited != 0 && splited[i])
		{
			if (!flag && ft_atol(splited[i], &arr[count_argv]) == -1)
				flag = -1;
			count_argv++;
			free(splited[i++]);
		}
		free(splited);
	}
	return (flag);
}
