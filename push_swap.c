/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:48:20 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/13 20:17:44 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
		splited = ft_split(*argv++, ' ');
		if (!splited)
			error("malloc error\n");
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

	i = 0;
	count_argv = 0;
	flag = 0;
	while (*argv)
	{
		splited = ft_split(*argv++, ' ');
		if (!splited)
			error("malloc error\n");
		i = 0;
		while (splited[i])
		{
			if (!flag && ft_atol(splited[i], &arr[count_argv]))
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
		error("malloc error\n");
	}
	
	ps->stack_a = NULL;
	ps->stack_b = NULL;

	ps->arr = array;
	ps->arr_size = size;
	
	ps->len_a = 0;
	ps->len_b = 0;
}
 
// // A function to implement bubble sort
 
// /* Function to print an array */
// void printArray(int *arr, int size)
// {
//     int i;
//     for (i=0; i < size; i++)
//         printf("%d ", arr[i]);
//     printf("\n");
// }

int main(int argc, char **argv)
{
	t_all ps;
	
	if (argc < 2)
		return (1);
	init_struct_t_all(&ps, ft_count_arrays(&argv[1]));
	if (parce_argv(ps.arr, &argv[1]) == -1)
	{
		free(ps.arr);
		free(ps.stack_a);
		error("parcing error\n");
	}
	if (ft_same_digits(ps.arr, ps.arr_size) == -1)
	{
		free(ps.arr);
		free(ps.stack_a);
		error("parcing error\n");
	}
	actions(&ps);
	// printf("Not sorted array: \n");
    // printArray(ps.arr, ps.arr_size);
	
	// bubbleSort(ps.arr, ps.arr_size);
	
    // printf("Sorted array: \n");
    // printArray(ps.arr, ps.arr_size);
}