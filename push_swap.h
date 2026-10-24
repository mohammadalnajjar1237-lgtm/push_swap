#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct stack{
    int value;
    struct stack *next;
}t_stack;

typedef struct stack_track 
{
    int size_of_stack;
    t_stack *top;    
} t_stack_track;

void	push_stack(t_stack **lst, t_stack *new);

int    fill_stack(char **args, t_stack **a, int av, int selector_flag);

t_stack   *create_stack(int value);

void    check_dups(char **integers);

 char	**free_all(char **strs);

 int	ft_atoi_m(const char *nptr);

 void    print_error();
char **ft_strjoin_m(char **splitted, char **integers);
int swap_a(t_stack *a);
t_stack	*ft_lstlast2(t_stack *lst);
void	ft_lstadd_back2(t_stack **lst, t_stack *new);
int push(t_stack *a, t_stack *b, char c);
int rotate(t_stack **a, char c);
int is_empty_or_unary(t_stack *a);
int reverse_rotate(t_stack **a, char c);
int rr(t_stack **a, t_stack **b);
int rrr(t_stack **a, t_stack **b);
void	sort_simple(t_stack *a, t_stack *b, t_bench *bench);
void	ft_lstadd_front(t_stack **lst, t_list *new);
#endif