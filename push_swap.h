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

 char	**free_all(char **strs);

 int	ft_atoi_m(const char *nptr);

 void    print_error();
char **ft_strjoin_m(char **splitted, char **integers);
int swap_a(t_stack *a);
t_stack	*ft_lstlast2(t_stack *lst);
void	ft_lstadd_back2(t_stack **lst, t_stack *new);
int push_a(t_stack *a, t_stack *b);
int push_b(t_stack *a, t_stack *b);
int rotate_a(t_stack **a);
int is_empty_or_unary(t_stack *a);
int reverse_rotate_a(t_stack **a);
#endif