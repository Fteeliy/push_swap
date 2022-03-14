/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:33:25 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/14 11:49:20 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_test
{
	int	*a;
	int	b;
	struct s_text	*next;
	
} t_test;

typedef struct s_list
{
	void			*content;
	int				score_a;
	int				score_b;
	struct s_list	*next;
	
} t_list;

typedef struct s_all
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*arr;
	int		arr_size;
	int		len_a;
	int		len_b;
	
} t_all;

void	init_struct_t_all(t_all *ps, int size);
int		parce_argv(int *not_sorted, char **argv);
int		ft_count_arrays(char **argv);
int		ft_same_digits(int *arr, int size);
int		ft_atol(const char *str, int *nbr);
char	**ft_split(char const *s, char c);
void	error(char *message);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *str);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif