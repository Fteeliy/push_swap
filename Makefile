# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 11:34:53 by wdwain            #+#    #+#              #
#    Updated: 2022/03/13 11:33:03 by wdwain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
HEADER = push_swap.h

SRC = ft_atol.c \
		ft_split.c \
		main.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_lstnew \
		ft_lstlast \
		ft_lstadd_back \
		ft_lstadd_front \
		utils.c \
		ft_strlen.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	
.PHONY: all clean fclean re