# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 11:34:53 by wdwain            #+#    #+#              #
#    Updated: 2022/03/17 18:08:43 by wdwain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_B = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
HEADER = push_swap.h
HEADER_B = push_swap.h gnl.h
T_FILE = .bonus

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
		actions.c \
		push.c \
		swap.c \
		rotate.c \
		reverse_rotate.c \
		mini_sort.c \
		sort.c \
		sort_utils.c \
		utils.c \

SRC_B = ft_atol.c \
		ft_split.c \
		checker.c \
		checker_utils.c \
		gnl.c \
		gnl_utils.c \
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
		actions.c \
		push.c \
		swap.c \
		rotate.c \
		reverse_rotate.c \
		mini_sort.c \
		sort.c \
		sort_utils.c \
		utils.c \
		
OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	${CC} -o $(NAME) $(OBJ)

%.o: %.c $(HEADER) $(HEADER_B) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

bonus: ${T_FILE}

${T_FILE}: ${OBJ_B}
	${CC} -o ${NAME_B} ${OBJ_B}
	@touch ${T_FILE}

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_B)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_B)

re: fclean all
	
.PHONY: all clean fclean re bonus