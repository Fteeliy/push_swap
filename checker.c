/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:56:42 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/17 18:42:29 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include "push_swap.h"

static	void	parcing(t_all *ps, char *line)
{
	if (!ft_strncmp(line, "ra\n", 4))
		ra(ps, 0);
	else if (!ft_strncmp(line, "rb\n", 4))
		rb(ps, 0);
	else if (!ft_strncmp(line, "rr\n", 4))
		rr(ps, 0);
	else if (!ft_strncmp(line, "rra\n", 5))
		rra(ps, 0);
	else if (!ft_strncmp(line, "rrb\n", 5))
		rrb(ps, 0);
	else if (!ft_strncmp(line, "rrr\n", 5))
		rrr(ps, 0);
	else if (!ft_strncmp(line, "pa\n", 4))
		pa(ps, 0);
	else if (!ft_strncmp(line, "pb\n", 4))
		pb(ps, 0);
	else if (!ft_strncmp(line, "sa\n", 4))
		sa(ps, 0);
	else if (!ft_strncmp(line, "sb\n", 4))
		sb(ps, 0);
	else if (!ft_strncmp(line, "ss\n", 4))
		ss(ps, 0);
	else
		error("Error\n");
}

static	void	get_operation(t_all *ps)
{
	char	*line;

	line = gnl(STDIN_FILENO);
	while (line)
	{
		parcing(ps, line);
		free(line);
		line = gnl(STDIN_FILENO);
	}
	free(line);
}

int	ft_count_arrays_c(char **argv)
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
	return (count_argv);
}

void	init_struct_t_all_c(t_all *ps, int size)
{
	int	*array;

	array = (int *)malloc(sizeof(int) * size);
	if (array == NULL)
	{
		lst_clear(ps);
		error("Error\n");
	}
	ps->stack_a = NULL;
	ps->stack_b = NULL;
	ps->arr = array;
	ps->arr_size = size;
	ps->len_a = 0;
	ps->len_b = 0;
}

int	main(int argc, char **argv)
{
	t_all	ps;

	if (argc == 1)
		return (EXIT_SUCCESS);
	init_struct_t_all_c(&ps, ft_count_arrays_c(&argv[1]));
	if (parce_argv_c(ps.arr, &argv[1]) == -1)
	{
		lst_clear(&ps);
		error("Error\n");
	}
	if (ft_same_digits_c(ps.arr, ps.arr_size) == -1)
	{
		lst_clear(&ps);
		error("Error\n");
	}
	fill_lst(&ps);
	get_operation(&ps);
	if (sorted(ps.stack_a) == 1 && ps.len_b == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	lst_clear(&ps);
	return (0);
}
