/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:48:20 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/16 21:10:26 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_same_digits(int *arr, int size)
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

int	ft_count_arrays(char **argv)
{
	char	**splited;
	int		i;
	int		count_argv;
	
	count_argv = 0;
	while (*argv)
	{
		if (!ft_strncmp("", *argv, 1) || !ft_strncmp (" ", *argv, 2))
			error("Error\n");
		splited = ft_split(*argv++, ' ');
		if (!splited)
			error("Error\n");
		i = 0;
		while (splited[i])
		{
			count_argv++;
			free(splited[i++]);
		}
		free(splited);
	}
	return(count_argv);
}

int	parce_argv(int *arr, char **argv)
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
		while (splited[i])
		{
			if (!flag && ft_atol(splited[i], &arr[count_argv]) == -1)
				flag = -1;
			count_argv++;
			free(splited[i++]);
		}
		free(splited);
	}
	return(flag);
}

void	init_struct_t_all(t_all *ps, int size)
{
	int	*array;

	array = (int *)malloc(sizeof(int) * size);
	if (array == NULL)
	{
		free(array);
		error("Error\n");
	}
	
	ps->stack_a = NULL;
	ps->stack_b = NULL;

	ps->arr = array;
	ps->arr_size = size;
	
	ps->len_a = 0;
	ps->len_b = 0;
}

int main(int argc, char **argv)
{
	t_all ps;
	
	if (argc < 2)
		return (1);
	init_struct_t_all(&ps, ft_count_arrays(&argv[1]));
	if (parce_argv(ps.arr, &argv[1]) == -1)
	{
		lst_clear(&ps);
		error("Error\n");
	}
	if (ft_same_digits(ps.arr, ps.arr_size) == -1)
	{
		lst_clear(&ps);
		error("Error\n");
	}
	actions(&ps);
	lst_clear(&ps);
	return (0);
}