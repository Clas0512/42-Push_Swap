SRC		= main.c checks.c checks_2.c r_commands.c \
			p_commands.c rr_commands.c s_commands.c \
			ft_sorting.c extra.c radix_sort.c 

OBJS	= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror
CC		= gcc

LBFT	= ./42-Libft-master/libft.a

NAME	= push_swap

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) $(LBFT) -o push_swap

clean:
	$(RM) -rf $(OBJS)

fclean:	clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re