#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "42-Libft-master/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
    int *a;
    int *b;
    int a_size;
    int b_size;
    int *each_arg_c;
}       t_stack;

void    ft_error(void);
int     ft_count_of_num(char *str, t_stack *stacks, int ac);
int     ft_general_check(char *str);
void    ft_isthr_cpy(t_stack *stacks);
void    ft_check_arg(int ac, char **argv, t_stack *stacks);
long    ft_atol(char *str);
void    ft_set_stack(t_stack *stacks, int ac, char **av);
int     ft_is_sorted(t_stack *stacks);

#endif
