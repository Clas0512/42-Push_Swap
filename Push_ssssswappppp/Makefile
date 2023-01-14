# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 00:18:43 by anargul           #+#    #+#              #
#    Updated: 2023/01/15 00:18:44 by anargul          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= main.c checks.c checks_2.c r_commands.c \
			p_commands.c rr_commands.c s_commands.c \
			ft_sorting.c extra.c radix_sort.c

OBJS	= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

CC		= gcc

LBFT	= ./Libft/libft.a

NAME	= push_swap

all: $(NAME)

$(NAME): $(SRC)
	@make -C ./Libft
	@$(CC) $(SRC) $(LBFT) -o push_swap

clean:
	@make clean -C ./Libft
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) -f $(NAME)
	@make clean -C ./Libft
	@make fclean -C ./Libft

re: fclean all

.PHONY: all clean fclean re