SRC		= main.c checks.c checks_2.c r_commands.c \
			p_commands.c rr_commands.c s_commands.c \
			ft_sorting.c

OBJS	= $(SRC:.c=.o)

LBFT	= ./42-Libft-master/libft.a

all:
		$(CC) $(SRC) $(LBFT) -o push_swap

clean:
		$(RM) -r $(OBJS)

fclean:	clean
		$(RM) run

re: fclean all

.PHONY: all clean fclean re