#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct stack{
    int value;
    struct stack *next;
}t_stack;

void	push(t_stack **lst, t_stack *new);

void    fill_stack(char **args, t_stack **a, int av, int selector_flag);

t_stack   *create_stack(int value);

void    check_dups(char **integers);

 char	**free_all(char **strs, int count);

 int	ft_atoi_m(const char *nptr);

 void    print_error();

#endif