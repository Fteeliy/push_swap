/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:33:25 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/17 18:54:27 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	int				score_a;
	int				score_b;
	struct s_list	*next;
}	t_list;

typedef struct s_all
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*arr;
	int		arr_size;
	int		len_a;
	int		len_b;
}	t_all;

void	error(char *message);
void	sort_distributor(t_all *ps);
int		sorted(t_list *lst);
void	fill_lst(t_all *ps);
int		actions(t_all *ps);
int		ft_same_digits(int *arr, int size);
int		parce_argv(int *arr, char **argv);
int		ft_same_digits_c(int *arr, int size);
int		parce_argv_c(int *arr, char **argv);
int		ft_count_arrays(char **argv);
int		ft_count_arrays_c(char **argv);
void	lst_clear(t_all *ps);
void	ft_swap(int *xp, int *yp);
void	bubble_sort(int *arr, int size);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
size_t	ft_strlen(const char *ch);
int		ft_atol(const char *str, int *nbr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	init_struct_t_all(t_all *ps, int size);
void	init_struct_t_all_c(t_all *ps, int size);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	presort3(t_all *ps);
void	sort3(t_all *ps);
void	sort5(t_all *ps);
int		c_ops(int a, int b);
void	executor(t_all *ps, t_list *el);
void	stack_a_sort(t_all *ps);
void	sort(t_all *ps);
void	pa(t_all *ps, int flag);
void	pb(t_all *ps, int flag);
void	sa(t_all *ps, int flag);
void	sb(t_all *ps, int flag);
void	ss(t_all *ps, int flag);
void	ra(t_all *ps, int flag);
void	rb(t_all *ps, int flag);
void	rr(t_all *ps, int flag);
void	rra(t_all *ps, int flag);
void	rrb(t_all *ps, int flag);
void	rrr(t_all *ps, int flag);

#endif