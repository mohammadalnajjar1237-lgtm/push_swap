#include "push_swap.h"
//itha ma esta3malet el capacity la tensa tem7eh

void    check_dups(char **integers)
{
    int i;
    int j;
    
    i = 0;
    while (integers[i + 1])
    {
        j = 1;
        while (integers[i + j])
        {
            if (ft_strncmp(integers[i + j], integers[i], 20) == 0)
            {
                free_all(integers);
                print_error();
            }
            j++;
        }
        i++;
    }
}

t_stack   *create_stack(int value)
{
    t_stack *a;
    a = malloc(sizeof(t_stack));
    a->value = value;
    a->next = NULL;
    return (a);
}

void	push(t_stack **lst, t_stack *new)
{
	t_stack	*new_head;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new_head = *lst;
	while (new_head->next != NULL)
		new_head = new_head->next;
	new_head->next = new;
}

void    fill_stack(char **args, t_stack **a, int av, int flags_num)
{
    char **integers;
    int i;
    int j;

    i = flags_num + 1;
    integers = NULL;
    while (i < av)
    {
        integers = ft_strjoin_m(ft_split(args[i], ' '), integers);//bedak t3mal free lal splitted o lal integers eli gabel
        i++;
    }
    check_dups(integers);
    j = 0;
    while (integers[j])
            push(a, create_stack(ft_atoi_m(integers[j++])));//lazm t3mal check lal errors bel atoi
    free_all(integers);
}
