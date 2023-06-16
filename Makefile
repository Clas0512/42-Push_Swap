NAME	= push_swap

SRC		= main.c checks.c checks_2.c r_commands.c \
			p_commands.c rr_commands.c s_commands.c \
			ft_sorting.c radix_sort.c index.c

OBJS	= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

CC		= gcc

LBFT	= ./Libft/libft.a

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