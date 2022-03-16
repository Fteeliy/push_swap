# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 11:34:53 by wdwain            #+#    #+#              #
#    Updated: 2022/03/16 21:51:58 by wdwain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
HEADER = push_swap.h

SRC = ft_atol.c \
		ft_split.c \
		push_swap.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_lstnew.c \
		ft_lstlast.c \
		ft_lstsize.c \
		ft_lstclear.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_strlen.c \
		ft_strncmp.c \
		push.c \
		swap.c \
		rotate.c \
		reverse_rotate.c \
		mini_sort.c \
		sort.c \
		sort_utils.c \
		utils.c \
		
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
	
.PHONY: all clean fclean re